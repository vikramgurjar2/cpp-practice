#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<long long, long long> solveGame(vector<int> &arr)
    {
        map<int, int> count;

        for (int i = 0; i < arr.size(); i++)
        {
            count[arr[i]]++;
        }

        vector<pair<int, int>> valueFreq;
        for (auto &entry : count)
        {
            valueFreq.push_back({entry.first, entry.second});
        }

        sort(valueFreq.begin(), valueFreq.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first > b.first; });

        long long player1Score = 0;
        long long player2Score = 0;
        long long moveCount = 0;

        for (int i = 0; i < valueFreq.size(); i++)
        {
            int value = valueFreq[i].first;
            int occurrences = valueFreq[i].second;

            for (int round = 0; round < value; round++)
            {
                if (moveCount % 2 == 0)
                {
                    player1Score += occurrences;
                }
                else
                {
                    player2Score += occurrences;
                }
                moveCount++;
            }
        }

        return make_pair(player1Score, player2Score);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int size;
        cin >> size;

        vector<int> array(size);
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }

        pair<long long, long long> scores = sol.solveGame(array);
        cout << scores.first << " " << scores.second << "\n";
    }

    return 0;
}