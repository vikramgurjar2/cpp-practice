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
        int n;
        cin >> n;

        vector<tuple<int, int, int>> ops;
        ops.emplace_back(1, 1, n);

        for (int i = 2; i <= n; ++i)
        {
            int pre_len = n - i + 1;
            int suf_start = pre_len + 1;
            ops.emplace_back(i, 1, pre_len);
            if (suf_start <= n)
            {
                ops.emplace_back(i, suf_start, n);
            }
        }

        // Output number of operations
        cout << ops.size() << '\n';

        // Fixed: Use get<> instead of structured binding
        for (const auto &op : ops)
        {
            cout << get<0>(op) << " " << get<1>(op) << " " << get<2>(op) << '\n';
        }
    }

    return 0;
}