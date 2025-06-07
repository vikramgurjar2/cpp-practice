#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        string str;
        cin >> str;
        map<char, long long> mp;
        for (auto x : str)
        {
            mp[x]++; /* code */
        }
        int total = mp.size();
        if (total == 4 || total == 3)
        {
            cout << 4 << endl;
        }
        else if (total == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            for (auto v : mp)
            {
                if (v.second == 3)
                {
                    cout << 6 << endl;
                    ans = 1;
                    break;
                }
            }
            if (ans == 0)
            {
                cout << 4 << endl;
            }
        }
    }

    return 0;
}