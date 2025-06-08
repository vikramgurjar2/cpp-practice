#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int array[n];
        int mid = n / 2;
        int j = mid - 1;
        int k = mid + 1;
        int flag = 0;
        array[mid] = n;
        int value = n - 1;
        while (j >= 0 || k < n)
        {
            if (flag == 0 && j >= 0)
            {
                array[j] = value;
                j--;
                value--;
                flag = 1;
            }
            else if (flag == 1 && k < n)
            {
                array[k] = value;
                k++;
                value--;
                flag = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return 0;
}