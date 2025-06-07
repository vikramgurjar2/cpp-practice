#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to calculate the number of unique shops visited starting from each shop
void countShops(const vector<int> &paths, vector<int> &result)
{
    int n = paths.size();
    vector<bool> visited(n, false); // To mark if a node is already processed

    for (int i = 0; i < n; ++i)
    {
        if (result[i] != -1)
            continue; // Skip already calculated nodes

        unordered_map<int, int> pathMap; // To detect cycles and store indices
        vector<int> path;                // To store the current path
        int current = i;

        while (!visited[current])
        {
            pathMap[current] = path.size();
            path.push_back(current);
            visited[current] = true;
            current = paths[current];
            if (pathMap.count(current))
            { // Cycle detected
                int cycleStartIndex = pathMap[current];
                int cycleLen = path.size() - cycleStartIndex;

                // Assign cycle lengths to all nodes in the cycle
                for (int j = cycleStartIndex; j < path.size(); ++j)
                {
                    result[path[j]] = cycleLen;
                }

                // Assign counts to all nodes before the cycle
                for (int j = cycleStartIndex - 1; j >= 0; --j)
                {
                    result[path[j]] = result[path[j + 1]] + 1;
                }
                break;
            }
        }

        // If we reach a node with a precomputed result, propagate back
        if (result[current] != -1)
        {
            for (int j = path.size() - 1; j >= 0; --j)
            {
                if (result[path[j]] == -1)
                {
                    result[path[j]] = result[current] + (path.size() - j);
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> paths(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> paths[i];
    }

    vector<int> result(n, -1); // To store the result for each shop
    countShops(paths, result);

    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
