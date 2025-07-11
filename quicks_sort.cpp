#include <iostream>
#include <stdlib.h>
using namespace std;
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int *A, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        int partitionIndex = partition(A, low, high); //
        quicksort(A, low, partitionIndex - 1);        // sorting of left partition
        quicksort(A, partitionIndex + 1, high);       // sorting of right partition
    }
}

int main()
{
    int A[] = {1, 4, 6, 11, 3, 2, 8, 5, 7, 9, 34};
    printArray(A, 11);
    quicksort(A, 1, 9);
    printArray(A, 11);

    return 0;
}