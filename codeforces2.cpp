#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
int A[n];
for (int i = 0; i < n; i++)
{
    /* code */cin>>A[i];
}
int m=0;
int b=0;
int i=0;
while(n){

if(A[i]%2==0){
    m+=A[i];
i++;
n--;
}
else if(A[i]%2!=0){
    b+=A[i];
i++;
n--;
}

}
//cout<<m<<b;

if(m>b){
    cout<<"YES";

}
else{
    cout<<"NO";
}


return 0;
}