#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t > 0)
    {
        long long n;
        long long k;
        cin >> n;
        cin >> k;
        // string s;
        // cin>>s;
        if (n % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (n % k == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (2 * x + k * y == n)
                    {
                        cout << "YES" << endl;
                        break;
                    }
                    else
                    {
                        cout << "YES";
                    }
                }
            }
        }

        // solve(n,c,s);
        cout << endl;
        t--;
    }

    return 0;
}