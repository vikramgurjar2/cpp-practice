#include<iostream>
using namespace std ;
int i;

int findelement(int arr[],int n ,int key ){
for(int i=0;i<n;i++){
if(arr[i]==key){
cout<<i<<endl;
   
    
}else{
    return -1;
}
}}

void displayarray(int arr[],int size){
    for(int i = 0;i<size;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
}




int incertionatlast(int arr[],int index,int element ){

arr[index]=element ;



}





int main(){
int arr[14]={1,3,5,6,4,6,4,4,3,8};
findelement(arr,10,6);
int size=10;
displayarray(arr,size);
size++;
printf("\n");
incertionatlast(arr,10,55);
displayarray(arr,size);
return 0;    
}