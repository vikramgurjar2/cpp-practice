#include <iostream>
#include <vector>
using namespace std;

class MuseumAnalyzer
{
private:
    vector<long long> events;
    vector<long long> totalSum, evenSum, oddSum;
    int n;

    void computePrefixArrays()
    {
        int size = 2 * n;
        totalSum.assign(size + 1, 0);
        evenSum.assign(size + 1, 0);
        oddSum.assign(size + 1, 0);

        for (int i = 0; i < size; i++)
        {
            totalSum[i + 1] = totalSum[i] + events[i];
            evenSum[i + 1] = evenSum[i] + (i % 2 == 0 ? events[i] : 0);
            oddSum[i + 1] = oddSum[i] + (i % 2 == 1 ? events[i] : 0);
        }
    }

    long long getSum(const vector<long long> &arr, int l, int r)
    {
        return arr[r + 1] - arr[l];
    }

public:
    void solve()
    {
        cin >> n;
        events.resize(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> events[i];
        }

        computePrefixArrays();

        for (int capacity = 1; capacity <= n; capacity++)
        {
            long long result = 0;

            // Handle overlapping visits for capacity > 1
            if (capacity > 1)
            {
                int overlap = capacity - 1;
                long long lastElements = getSum(totalSum, 2 * n - overlap, 2 * n - 1);
                long long firstElements = getSum(totalSum, 0, overlap - 1);
                result += lastElements - firstElements;
            }

            // Handle remaining elements with optimal pairing
            int leftBound = capacity - 1;
            int rightBound = 2 * n - capacity;

            if (leftBound <= rightBound)
            {
                long long oddContrib = getSum(oddSum, leftBound, rightBound);
                long long evenContrib = getSum(evenSum, leftBound, rightBound);

                // Determine correct pairing based on starting position parity
                if (leftBound % 2 == 0)
                {
                    result += oddContrib - evenContrib;
                }
                else
                {
                    result += evenContrib - oddContrib;
                }
            }

            cout << result;
            if (capacity < n)
                cout << " ";
        }
        cout << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    MuseumAnalyzer analyzer;
    while (tests--)
    {
        analyzer.solve();
    }

    return 0;
}