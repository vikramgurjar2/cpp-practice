#include <iostream>
#include <vector>
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
        cin >> n;

        vector<int> a(n);
        int zeros = 0;
        int negative = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                zeros++;
            }
            else if (a[i] == -1)
            {
                negative++;
            }
        }

        int operations = zeros;

        if (negative % 2 == 1)
        {
            operations += 2;
        }

        cout << operations << "\n";
    }

    return 0;
}