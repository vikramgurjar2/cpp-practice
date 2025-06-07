#include <iostream>
using namespace std;

void find_duplicates(int arr[], int n)
{
    cout << "Duplicates: ";
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]);
        if (arr[index] < 0)
        {
            cout << index << " ";
        }
        arr[index] *= -1;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 3, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_duplicates(arr, n);
    return 0;
}
