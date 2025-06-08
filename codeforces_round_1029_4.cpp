#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;

        // Count matches at all positions
        int matches = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == b[i])
                matches++;
        }

        // The best answer is n-1 (by matching all but the last, as explained)
        // But if a[n-1] == b[n-1], we can get n matches
        int answer = n - 1 + (a[n - 1] == b[n - 1]);

        // Try removing each index, but only removing a mismatch can help
        // Removing a matched index reduces matches by 1, so only consider mismatches
        // Removing the last index: matches - (a[n-1] == b[n-1])
        answer = max(answer, matches - (a[n - 1] == b[n - 1]));

        cout << answer << '\n';
    }
    return 0;
}
