#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        bool possible = true;

        // Check for invalid patterns
        // 1. Check if there's a single 0 between 1s
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1')
            {
                possible = false;
                break;
            }
        }

        // 2. Check boundary conditions
        // If string starts with "01..."
        if (n >= 2 && s[0] == '0' && s[1] == '1')
        {
            possible = false;
        }

        // If string ends with "...10"
        if (n >= 2 && s[n - 2] == '1' && s[n - 1] == '0')
        {
            possible = false;
        }

        if (!possible)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        // Construct the permutation
        vector<int> p(n + 1);
        vector<bool> used(n + 1, false);
        vector<int> stable_positions;

        // First, place stable elements (where s[i] = '1') in their positions
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1')
            {
                p[i] = i;
                used[i] = true;
                stable_positions.push_back(i);
            }
        }
        if (stable_positions.size() == 0)
        {
            // All positions are unstable, just print n to 1
            for (int i = n; i >= 1; i--)
            {
                cout << i;
                if (i > 1)
                    cout << " ";
            }
            cout << "\n";
            continue;
        }
        else
        {
            int left = 0;
            for (auto pos : stable_positions)
            {
                int right = pos;
                // fill left to right-1 in reverse order
                for (int i = right - 1; i >= left + 1; i--)
                {
                    p[i] = left + right - i;
                }
                left = right;
            }
            // fill the last segment in reverse order if any
            for (int i = n; i >= left + 1; i--)
            {
                p[i] = left + n - i + 1;
            }

            for (int i = 1; i <= n; i++)
            {
                cout << p[i];
                if (i < n)
                    cout << " ";
            }
            cout << "\n";
        }
        // int current=stable_positions[0];

        // Then, place unstable elements (where s[i] = '0')

        // Output the permutation
    }

    return 0;
}