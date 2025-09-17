#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int mod = 998244353;

struct Hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<long long>()(((long long)p.first << 32) | p.second);
    }
};

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> x(n), y(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }

        unordered_map<pair<int, int>, long long, Hash> mp;

        // Base case
        mp[{x[0], y[0]}]++;
        mp[{y[0], x[0]}]++;

        for (int i = 1; i < n; i++)
        {
            unordered_map<pair<int, int>, long long, Hash> nxt;

            for (auto &p : mp)
            {
                auto st = p.first;
                long long cnt = p.second;
                int u = st.first;
                int v = st.second;

                // No swap
                if (x[i] >= u && y[i] >= v)
                {
                    nxt[{x[i], y[i]}] = (nxt[{x[i], y[i]}] + cnt) % mod;
                }

                // Swap
                if (y[i] >= u && x[i] >= v)
                {
                    nxt[{y[i], x[i]}] = (nxt[{y[i], x[i]}] + cnt) % mod;
                }
            }

            mp = nxt;
        }

        long long ans = 0;
        for (auto &p : mp)
        {
            ans = (ans + p.second) % mod;
        }

        cout << ans << "\n";
    }

    return 0;
}