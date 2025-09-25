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
        long long h, d;
        cin >> h >> d;

        long long position = 0;
        long long health = h;
        long long turns = 0;
        long long next_consecutive_cost = 1; // Global consecutive counter

        while (position < d)
        {
            // Check if we can make the next move
            if (health > next_consecutive_cost)
            {
                // Make the move
                position++;
                health -= next_consecutive_cost;
                turns++;
                next_consecutive_cost++; // Next move will cost more
            }
            else
            {
                // Cannot make move, must rest
                health++;
                turns++;
                next_consecutive_cost = 1; // Reset consecutive counter
            }
        }

        cout << turns << "\n";
    }

    return 0;
}
