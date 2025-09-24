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
        int x, y;
        cin >> x >> y;
        int ans = -1;
        if (x < y)
        {
            ans = 2;
        }
        else if (x == y)
        {
            ans = -1;
        }
        else if (x > y && x >= y + 2 && y > 1)
        {
            ans = 3;
        }
        else
        {
            ans = -1;
        }
        cout << ans << "\n";
    }

    return 0;
}
