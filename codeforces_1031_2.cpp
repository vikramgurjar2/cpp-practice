#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string ans(n, '?');
        // Find the type of s1
        cout << "? 2 1 2\n";
        cout.flush();
        int f12;
        cin >> f12;
        cout << "? 2 2 1\n";
        cout.flush();
        int f21;
        cin >> f21;

        char s1, s2;
        if (f12 == 1 && f21 == 0)
        {
            s1 = '(';
            s2 = ')';
        }
        else if (f12 == 0 && f21 == 1)
        {
            s1 = ')';
            s2 = '(';
        }
        else if (f12 == 0 && f21 == 0)
        {
            s1 = '(';
            s2 = '(';
        }
        else
        {
            s1 = ')';
            s2 = ')';
        }

        ans[0] = s1;
        ans[1] = s2;

        for (int i = 2; i < n; ++i)
        {
            cout << "? 2 1 " << (i + 1) << "\n";
            cout.flush();
            int f;
            cin >> f;
            if (f == 1)
                ans[i] = (ans[0] == '(' ? ')' : '(');
            else
                ans[i] = ans[0];
        }

        cout << "! " << ans << endl;
        cout.flush();
    }
}
