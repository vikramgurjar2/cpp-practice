#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int x;
        cin >> n;
        cin >> x;
        int array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        /// will write code here
        int index = 0;
        while (index < n && array[index] == 0)
        {
            index++;
        }
        if (index == n)
        {
            cout << "yes" << endl;
        }
        else
        {
            index += x;
            if (index >= n)
            {
                cout << "yes" << endl;
            }
            else if (index < n)
            {
                while (index < n && array[index] == 0)
                {
                    index++;
                }
                if (index == n)
                {
                    cout << "yes" << endl;
                }
                else
                {
                    cout << "no" << endl;
                }
            }
        }
    }
    return 0;
}