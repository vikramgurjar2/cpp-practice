#include<stdio.h>
using namespace std;



int main(){
int arr[100]={0,1,2,3,4,5,6,7,8,9};
int n=10 ,i;
for(int i=0;i<n;i++){
    printf("%d\n",arr[i]);
}

///shifting in position of element 
int pos=4,x = 34 ; 
for(int i=n-1;i>=pos;i--){
    arr[i+1]=arr[i];
    arr[pos-1]= 78;
}

n++;
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
return 0;
}