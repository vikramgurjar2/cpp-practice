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
        long long y;
        cin >> n >> y;

        vector<int> arr(n);
        unordered_map<int, int> mp;
        int max_val = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            if (arr[i] > max_val)
                max_val = arr[i];
        }

        long long max_income = LLONG_MIN;

        // Key optimization: limit x to 1000 maximum
        int limit = min(max_val + 1, 1000);

        for (int x = 2; x <= limit; x++)
        {
            unordered_map<int, int> new_mp;
            long long total = 0;

            for (int i = 0; i < n; i++)
            {
                int price = (arr[i] + x - 1) / x; // ceiling division
                new_mp[price]++;
                total += price;
            }

            long long tags = 0;
            for (auto &it : new_mp)
            {
                if (it.second > mp[it.first])
                {
                    tags += (it.second - mp[it.first]);
                }
            }

            long long income = total - tags * y;
            if (income > max_income)
                max_income = income;
        }

        cout << max_income << "\n";
    }

    return 0;
}
