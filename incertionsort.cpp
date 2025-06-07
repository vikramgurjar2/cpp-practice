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
void incertionsort(int* arr,int size){
    int key,j;
for (int i = 1; i < size; i++)
{   key =  arr[i] ;
    j = i-1;  

 
  
        while (j>=0 && arr[j]>key/* condition */)
        {
            /* code */
            arr[j+1]= arr[j]    ;
            j--;
                }
        
       arr[j+1] =key;
    
   }
   
}




int main()
{
    int arr[] = {1,2,3,49,57,69,17,8};
    printarr(arr, 8);
    incertionsort(arr, 8);
    cout << endl;
    printarr(arr, 8);
    return 0;
}