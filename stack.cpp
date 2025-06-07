#include<iostream>
#include<stdio.h>    
using namespace std;
#define n 100

class stack{
private:
 int* arr; 
int top ;

public:
stack(){
 arr=new int[n];
 top =-1;
}
void  push(int x){
    if(top==n-1){
        cout<<"the stack is filled "<<endl;
        return ;
    }
    top++;
arr[top]=x;
               
}
void  pop(){
    if(top==-1){
        cout<<"the stack is empty "<<endl;
        return ;
    }
    top--;
}

int   Top(){
    if(top==-1){
        cout<<" the stack is empty "<<endl;
        return-1; 

    }
return arr[top];

}
bool empty(){

    return top==-1;
}
};
int peak(struct stack *sp,int i){
    if(sp->top-i +1<0){
        prinf("the value id not valid ");
        return -1;
    }
    else{
        return sp->arr
    }
}

int main(){
    stack st;
    st.push(23);
    st.push(21);
    st.push(23);
    st.push(25);
    st.push(28);

cout<<"the value of the top is "<<st.Top()<<endl;
st.pop();
st.pop();
st.pop();

cout<<"the value of the top is "<<st.Top()<<endl;
st.empty();
    return 0;

}





