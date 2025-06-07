#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        int n;
        int k;
        int arr[n];
        cin >> n >> k;
        bool res = true;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (k == 1 && !is_sorted(arr, arr + n))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
