#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &pos)
{
    if (pos.empty())
        return LLONG_MAX;

    int n = pos.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[i] = pos[i] - i;
    }

    sort(temp.begin(), temp.end());

    int m = temp[n / 2];

    long long res = 0;
    for (int pos : temp)
    {
        res += abs(pos - m);
    }

    return res;
}

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
        string s;
        cin >> s;

        vector<int> pos_a, pos_b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                pos_a.push_back(i);
            else
                pos_b.push_back(i);
        }

        if (pos_a.empty())
        {
            cout << 0 << "\n";
            continue;
        }
        if (pos_b.empty())
        {
            cout << 0 << "\n";
            continue;
        }

        long long minA = solve(pos_a);
        long long minB = solve(pos_b);

        cout << min(minA, minB) << "\n";
    }

    return 0;
}
