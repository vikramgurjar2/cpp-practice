#include<iostream>
using namespace std;
#define n 10
class stack{
private :
int top  ;
int* arr; 


public:
stack(){
    arr = new int[n];
    top=-1;
}
void push(int x){
    if(top==n-1){
        printf("the stack  is filled ");
        return ;
    }
    top++;
    arr[top]= x;
}
int Top(){
if(top==-1){
    printf("the stack is empty ");
    return -1;
}
else{
    return arr[top];
}

}







};






int main(){
    stack st;
    
    st.push(34);
    cout<<st.Top();
return 0;
}