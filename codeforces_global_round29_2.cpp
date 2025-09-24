#include <iostream>
#include <vector>
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
        cin >> n;

        vector<int> result(2 * n);

        int i = 0;
        int num = n;
        while (num > 0)
        {
            result[i] = num;
            num--;
            i++;
        }
        result[n] = n;
        i = n + 1;
        num = 1;
        while (i < 2 * n)
        {
            result[i] = num;
            num++;
            i++;
        }

        // Print result
        for (int i = 0; i < 2 * n; i++)
        {
            cout << result[i];
            if (i < 2 * n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}