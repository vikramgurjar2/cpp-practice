#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getAbs(ll x)
{
    return x < 0 ? -x : x;
}

bool isValid(ll x, ll n)
{
    return x >= 0 && x <= n;
}

bool checkTime(ll n, ll kr, ll kc, ll dr, ll dc, ll time)
{
    ll minR = dr - time, maxR = dr + time;
    ll minC = dc - time, maxC = dc + time;

    auto inDoranRange = [&](ll r, ll c) -> bool
    {
        return r >= minR && r <= maxR && c >= minC && c <= maxC;
    };

    vector<pair<ll, ll>> escapePoints;

    auto addPoint = [&](ll r, ll c)
    {
        if (r < 0)
            r = 0;
        if (r > n)
            r = n;
        if (c < 0)
            c = 0;
        if (c > n)
            c = n;
        if (getAbs(r - kr) + getAbs(c - kc) <= time)
        {
            escapePoints.push_back({r, c});
        }
    };

    // Check positions at maximum distance from Krug
    if (isValid(kr - time, n))
        addPoint(kr - time, kc);
    if (isValid(kr + time, n))
        addPoint(kr + time, kc);
    if (isValid(kc - time, n))
        addPoint(kr, kc - time);
    if (isValid(kc + time, n))
        addPoint(kr, kc + time);

    // Check positions along top and bottom edges
    for (int edge = 0; edge < 2; edge++)
    {
        ll row = (edge == 0) ? 0 : n;
        ll rowDist = getAbs(row - kr);
        if (rowDist <= time)
        {
            ll remaining = time - rowDist;
            ll col1 = kc - remaining;
            ll col2 = kc + remaining;
            if (col1 < 0)
                col1 = 0;
            if (col1 > n)
                col1 = n;
            if (col2 < 0)
                col2 = 0;
            if (col2 > n)
                col2 = n;
            addPoint(row, col1);
            addPoint(row, col2);
        }
    }

    // Check positions along left and right edges
    for (int edge = 0; edge < 2; edge++)
    {
        ll col = (edge == 0) ? 0 : n;
        ll colDist = getAbs(col - kc);
        if (colDist <= time)
        {
            ll remaining = time - colDist;
            ll row1 = kr - remaining;
            ll row2 = kr + remaining;
            if (row1 < 0)
                row1 = 0;
            if (row1 > n)
                row1 = n;
            if (row2 < 0)
                row2 = 0;
            if (row2 > n)
                row2 = n;
            addPoint(row1, col);
            addPoint(row2, col);
        }
    }

    // Check all four corners
    addPoint(0, 0);
    addPoint(0, n);
    addPoint(n, 0);
    addPoint(n, n);

    // If any escape point is outside Doran's range, Krug can survive
    for (auto &point : escapePoints)
    {
        if (!inDoranRange(point.first, point.second))
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    ll n, kr, kc, dr, dc;
    cin >> n >> kr >> kc >> dr >> dc;

    ll low = 0, high = 2 * n;
    ll ans = -1;

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (checkTime(n, kr, kc, dr, dc, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (ans < 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
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