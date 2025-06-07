#include <iostream>
#include<queue>
using namespace std;

class heap
{

public:
    int arr[100];
    int size ;

    heap{
        arr[0]=-1;
        size = 0;

    } 
    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1]=arr[size];

        int i =1;
        while(i<size){
            int leftindex=2*i;
            int rightindex= 2*i +1;
            if(leftindex < size && arr[i]< arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < size && arr[i]<arr[rightindex]){
               swap(arr[i],arr[rightindex]);
               i=rightindex;
 
            }
            else{
                return;
            }
        }



    }





    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                int temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";

        }
        cout<<"...."<<endl;
    }

};


void heapify(int arr[],int n,int i){

    int largest = i;
    int left =2*i;
    int right = 2*i+1;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(i != largest){
      swap(arr[largest],arr[i]);
    }


}
void heapsort(int arr[],n ){
int size =n;

while(size>1){
    swap(arr[size],arr[1]);
    size--;
    heapify(arr,size,1);

}




}






int
main()
{
  heap h;
  h.insert(50);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.insert(56);
  h.insert(50);
  h.print();
  int arr[6]={-1,54,53,52,52,50};
  int n= 5;
  for(int i=n/2;i>0;i--){
    heapify(arr,n,i);
  }
  cout<<"printing the array after heapify"<<endl;
  for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;


priority_queue<int> pq;
pq.push(1);
pq.push(2);
pq.push(3);
pq.push(4);
pq.push(5);
pq.push(6);
cout<<"the top of pq is "<<pq.top()<<endl;







    return 0;
}