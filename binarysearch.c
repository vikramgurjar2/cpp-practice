#include <stdio.h>
int i;

int binarysearch(int arr[], int size, int element)
{
    int mid, low, high;
    low = 0;
    high = size - 1;
    //start searching 
    while (low<=high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
  int arr[] = {1, 3, 6, 8, 9, 12, 13, 17, 23, 34, 56, 78, 89};
    int size = sizeof(arr)/sizeof(int);
    int element = 23;
    binarysearch(arr, size, element );
int searchIndex = binarysearch(arr, size, element );
 printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}
