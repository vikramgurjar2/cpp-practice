#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> seq(n);
        vector<int> count(m + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int len;
            cin >> len;
            seq[i].resize(len);

            for (int j = 0; j < len; j++)
            {
                cin >> seq[i][j];
                count[seq[i][j]]++;
            }
        }

        bool temp = true;
        for (int i = 1; i <= m; i++)
        {
            if (count[i] == 0)
            {
                temp = false;
                break;
            }
        }

        if (!temp)
        {
            cout << "NO" << endl;
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool res = false;

            for (int val : seq[i])
            {
                if (count[val] == 1)
                {
                    res = true;
                    break;
                }
            }

            if (!res)
            {
                ans++;
            }
        }

        cout << (ans >= 2 ? "YES" : "NO") << endl;
    }

    return 0;
}