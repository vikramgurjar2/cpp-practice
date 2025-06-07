#include <iostream>
#include <stdio.h>
using namespace std;
int printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        /* code */

        printf("%d\n", arr[i]);
    }
}
void selectionsort(int *arr, int n)
{  cout<<"running selectionsort "<<endl;
    int indofmin, temp;

    for (int i = 0; i < n - 1; i++)
    {
        indofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indofmin])
            {
                /* code */ indofmin = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[indofmin];
        arr[indofmin] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 49, 57, 69, 17, 8};
    printarr(arr, 8);
    selectionsort(arr, 8);
   
    printarr(arr, 8);
    return 0;
}