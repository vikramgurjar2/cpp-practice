#include <iostream>
#include <vector>
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
        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        pair<int, int> ans = {0, 0};
        int s1 = 0;
        for (int l = 0; l < n - 2; l++)
        {
            s1 += arr[l];
            int s2 = 0;
            for (int r = l + 1; r < n - 1; r++)
            {
                s2 += arr[r];
                int s3 = sum - s1 - s2;
                if (s1 % 3 == s2 % 3 && s2 % 3 == s3 % 3)
                {
                    ans = {l + 1, r + 1};
                    break;
                }
                if (s1 % 3 != s2 % 3 && s2 % 3 != s3 % 3 && s1 % 3 != s3 % 3)
                {
                    ans = {l + 1, r + 1};
                    break;
                }
            }
            if (ans.first != 0)
                break;
        }
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
