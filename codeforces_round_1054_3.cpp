#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Count presence of numbers 0 to k-1
        vector<bool> present(k, false);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < k)
            {
                present[a[i]] = true;
            }
            else if (a[i] == k)
            {
                count++;
            }
        }

        // Count missing numbers from 0 to k-1
        int missed = 0;
        for (int i = 0; i < k; i++)
        {
            if (!present[i])
            {
                missed++;
            }
        }

        cout << max(missed, count) << "\n";
    }

    return 0;
}
