#include <iostream>
#include <stdio.h>
int printarr(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        /* code */

        printf("%d\n", A[i]);
    }
}
void merge(int *A, int l, int h, int m)
{
    int i, j, k;
    i = l;
    j = m + 1;
    k = 0;
    int B[20];
    while (i <= m && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++, k++;
        }
        else
        {
            B[j] = A[j];
            j++, k++;
        }}
        while (i <= m)
        {
            B[k] = A[i];
            i++, k++;
        }
        while (j <= h)
        {
            B[k] = A[j];
            j++, k++;
        }
    
    for (int i = l; i <=h; i++)
    {
       A[i]=B[i];
    }
    
}

using namespace std;
int main()
{
    int A[] = {5,6,7,9,8,10,13,14};
printarr(A,8);
 merge(A , 0, 7, 4);
 cout<<"printing mergesort"<<endl;

 printarr(A,9);
return 0;
}
