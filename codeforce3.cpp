#include <bits/stdc++.h>

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            priority_queue<int> pq;
            for (int i = l - 1; i < r; i++)
            {
                pq.push(a[i]);
            }
            int robin = 0;
            int sherrif = 0;
            bool flag = true;
            while (!pq.empty())
            {
                if (flag == true)
                {
                    robin += pq.top();
                    pq.pop();
                    flag = false;
                }
                else
                {
                    sherrif += pq.top();
                    pq.pop();
                    flag = true;
                }
            }
            if (robin <= sherrif)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}