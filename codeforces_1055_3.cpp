#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> buildPrefix(const vector<int> &arr, int val)
{
    int n = arr.size() - 1;
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        res[i] = res[i - 1];
        if (arr[i] == val)
            res[i]++;
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<int> zeros = buildPrefix(arr, 0);
    vector<int> ones = buildPrefix(arr, 1);

    vector<int> temp(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        temp[i] = temp[i - 1];
        if (arr[i] == arr[i + 1])
            temp[i]++;
    }
    temp[n] = temp[n - 1];

    while (q--)
    {
        int left, right;
        cin >> left >> right;

        int curr0 = zeros[right] - zeros[left - 1];
        int curr1 = ones[right] - ones[left - 1];

        if (curr0 % 3 != 0 || curr1 % 3 != 0)
        {
            cout << -1 << '\n';
            continue;
        }

        int res = (curr0 + curr1) / 3;

        if (right > left)
        {
            int curr = temp[right - 1] - temp[left - 1];
            if (curr == 0)
                res++;
        }
        else
        {
            res++;
        }

        cout << res << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}