#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &a, int n, int k, int l, int r)
{
    if (k == 0)
        return 0;

    long long count = 0;
    unordered_map<int, int> freq;
    int left = 0, dist = 0;

    for (int right = 0; right < n; right++)
    {
        if (freq[a[right]] == 0)
        {
            dist++;
        }
        freq[a[right]]++;

        while (dist > k)
        {
            freq[a[left]]--;
            if (freq[a[left]] == 0)
            {
                dist--;
            }
            left++;
        }

        int st = max(left, right - r + 1);
        int mt = right - l + 1;

        if (st <= mt)
        {
            count += mt - st + 1;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, l, r;
        cin >> n >> k >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long result = solve(a, n, k, l, r) - solve(a, n, k - 1, l, r);
        cout << result << "\n";
    }

    return 0;
}
