#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    vector<int> testVals(numTests);
    int biggestVal = 0;
    for (int i = 0; i < numTests; i++)
    {
        cin >> testVals[i];
        biggestVal = max(biggestVal, testVals[i]);
    }

    int limit = biggestVal + 2;
    vector<vector<int>> allDivisors(biggestVal + 1);

    for (int d = 3; d <= biggestVal; d++)
    {
        for (int m = d; m <= biggestVal; m += d)
        {
            allDivisors[m].push_back(d);
        }
    }

    vector<int> minSteps(biggestVal + 1, INF), minSubtreeSize(limit + 1, INF);
    minSteps[1] = 0;
    if (biggestVal >= 2)
        minSteps[2] = INF;

    for (int val = 3; val <= limit; val++)
    {
        minSubtreeSize[val] = 1 + minSteps[val - 2];
        if (val > biggestVal)
            break;

        minSteps[val] = minSubtreeSize[val];

        for (int d : allDivisors[val])
        {
            int q = val / d;
            if (minSteps[q] < INF)
            {
                minSteps[val] = min(minSteps[val], minSteps[q] + minSubtreeSize[d]);
            }
        }
    }

    for (int val : testVals)
    {
        if (val == 1)
        {
            cout << 1 << "\n";
        }
        else if (minSteps[val] >= INF)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << 1 + minSteps[val] << "\n";
        }
    }

    return 0;
}
