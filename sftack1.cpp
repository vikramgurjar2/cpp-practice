#include <iostream>
#include <stdio.h>
using namespace std;
#define n 100

class stack
{
private:
    int* arr;
    int  top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n-1)
        {
            cout << "the stack is filled " << endl;
            return;
        }

        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "the stack is empty " << endl;
            return ;
        }
        top--;
    }
int Top()
    {
        if (top == -1)
        {
            cout << "the arr is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {

        return top == -1;
    }
};

int main()
{
    stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    cout << "the vlue of top is " << st.Top() << endl;
    st.pop();
cout << "the vlue of top is " << st.Top() << endl;
    return 0;
}