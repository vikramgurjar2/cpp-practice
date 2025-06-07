#include <iostream>
using namespace std;
int printarr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        /* code */

        printf("%d\n", arr[i]);
    }
}
void bubblesort(int *arr, int size)
{ int issorted =0;
    int temp;
    for (int i = 0; i < size - 1; i++)
    { issorted =1;
    printf("working in %d\n:",i+1);
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                /* code */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted =0;
            }
        }
        if(issorted){
            return;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    printarr(arr, 8);
    bubblesort(arr, 8);
    cout << endl;
    printarr(arr, 8);
    return 0;
}