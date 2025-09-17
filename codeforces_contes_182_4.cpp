#include <bits/stdc++.h>
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
        long long y;
        cin >> n >> y;

        vector<long long> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        long long max_income = LLONG_MIN;

        // Try different values of x
        long long max_c = *max_element(c.begin(), c.end());

        for (long long x = 2; x <= max_c + 1; x++)
        {
            // Calculate new prices using ceiling division
            vector<long long> new_prices(n);
            for (int i = 0; i < n; i++)
            {
                new_prices[i] = (c[i] + x - 1) / x;
            }

            // Count frequency of original prices
            map<long long, int> original_count;
            for (int i = 0; i < n; i++)
            {
                original_count[c[i]]++;
            }

            // Count frequency of new prices needed
            map<long long, int> new_count;
            for (int i = 0; i < n; i++)
            {
                new_count[new_prices[i]]++;
            }

            // Calculate how many new tags we need to print
            long long tags_to_print = 0;
            for (map<long long, int>::iterator it = new_count.begin();
                 it != new_count.end(); ++it)
            {
                long long price = it->first;
                int needed = it->second;
                int available = original_count[price];
                if (needed > available)
                {
                    tags_to_print += needed - available;
                }
            }

            // Calculate total income
            long long total_new_price = 0;
            for (int i = 0; i < n; i++)
            {
                total_new_price += new_prices[i];
            }

            long long cost = tags_to_print * y;
            long long income = total_new_price - cost;

            max_income = max(max_income, income);
        }

        cout << max_income << "\n";
    }

    return 0;
}
