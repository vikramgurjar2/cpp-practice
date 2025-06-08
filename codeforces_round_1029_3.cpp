#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        unordered_set<int> current_segment;
        unordered_set<int> required;
        unordered_map<int, int> required_counts;
        int count = 0;
        int remaining = 0;

        for (int i = 0; i < n; ++i)
        {
            int num = a[i];
            current_segment.insert(num);

            if (required.empty())
            {
                // First segment
                required = current_segment;
                count++;
                current_segment.clear();
                required_counts.clear();
                for (int x : required)
                {
                    required_counts[x] = 1;
                }
                remaining = required.size();
            }
            else
            {
                if (required.find(num) != required.end())
                {
                    required_counts[num]--;
                    if (required_counts[num] == 0)
                    {
                        remaining--;
                    }
                }

                if (remaining == 0)
                {
                    count++;
                    required = current_segment;
                    current_segment.clear();
                    required_counts.clear();
                    for (int x : required)
                    {
                        required_counts[x] = 1;
                    }
                    remaining = required.size();
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}
