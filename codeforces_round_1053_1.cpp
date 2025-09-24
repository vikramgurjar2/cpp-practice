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
        vector<int> seq(m);
        for (int i = 0; i < m; i++)
        {
            cin >> seq[i];
        }
        /// to check if sequence is strictly increasing order
        bool temp = true;
        for (int i = 1; i < m; i++)
        {
            if (seq[i] <= seq[i - 1])
            {
                temp = false;
                break;
            }
        }
        if (!temp)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            int ans = 0;
            int maxi = seq[m - 1];
            ans = n - maxi + 1;
            cout << ans << endl;
        }
    }

    return 0;
}