#include <iostream>
using namespace std;

#define ll long long
#define MOD 1000000007
#define endl "\n"

// Function to calculate the sum of first n natural numbers
ll sum_of_natural_numbers(ll n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long leaves = 0;

        // Calculate leaves directly without storing large arrays
        if (k >= n)
        {
            leaves = sum_of_natural_numbers(n);
        }
        else
        {
            leaves = sum_of_natural_numbers(n) - sum_of_natural_numbers(n - k);
        }

        if (leaves % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
