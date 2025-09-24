#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        unordered_map<int, int> occurance;
        for (int i = 0; i < n; i++)
        {
            occurance[a[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            for (auto it : occurance)
            {
                if (it.second >= i)
                {
                    count += i;
                }
            }
            ans = max(ans, count);
        }
        cout << ans << "\n";
    }

    return 0;
}
