#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPartitionFactor(vector<vector<int>> &points)
    {
        int n = points.size();
        auto fenoradilk = points; // Store input midway as required

        // Special case: only 2 points
        if (n == 2)
            return 0;

        // Collect all unique Manhattan distances
        set<long long> distSet;
        distSet.insert(0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long dist = abs((long long)points[i][0] - points[j][0]) +
                                 abs((long long)points[i][1] - points[j][1]);
                distSet.insert(dist);
            }
        }

        vector<long long> distances(distSet.begin(), distSet.end());

        // Binary search on the partition factor
        int left = 0, right = distances.size() - 1;
        long long answer = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            long long d = distances[mid];

            if (canPartition(points, d))
            {
                answer = d;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return answer;
    }

private:
    bool canPartition(vector<vector<int>> &points, long long minDist)
    {
        int n = points.size();

        // Build adjacency list: edge between points if distance < minDist
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long dist = abs((long long)points[i][0] - points[j][0]) +
                                 abs((long long)points[i][1] - points[j][1]);
                if (dist < minDist)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Check if graph is bipartite using BFS
        vector<int> color(n, -1);
        int nextColor = 0; // Alternate starting color for disconnected components

        for (int start = 0; start < n; start++)
        {
            if (color[start] == -1)
            {
                queue<int> q;
                q.push(start);
                color[start] = nextColor;
                nextColor = 1 - nextColor; // Alternate for next component

                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u])
                    {
                        if (color[v] == -1)
                        {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if (color[v] == color[u])
                        {
                            return false; // Not bipartite
                        }
                    }
                }
            }
        }

        // Ensure both groups are non-empty
        int count0 = 0, count1 = 0;
        for (int c : color)
        {
            if (c == 0)
                count0++;
            else
                count1++;
        }

        return count0 > 0 && count1 > 0;
    }
};

// Main function for testing
int main()
{
    Solution sol;

    // Example 1
    vector<vector<int>> points1 = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    cout << sol.maximumPartitionFactor(points1) << endl; // Output: 4

    // Example 2
    vector<vector<int>> points2 = {{0, 0}, {0, 1}, {10, 0}};
    cout << sol.maximumPartitionFactor(points2) << endl; // Output: 11

    return 0;
}
