#include <iostream>
#include <vector>
#include <algorithm>
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int max_diff = 0;
        for (int i = 0; i < n; i += 2)
        {
            int diff = abs(a[i + 1] - a[i]);
            max_diff = max(max_diff, diff);
        }

        cout << max_diff << "\n";
    }

    return 0;
}