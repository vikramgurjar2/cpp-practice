#include <iostream>
using namespace std;

class complex
{
    int a;
    int b;

public:
   complex(int x,int y){
       a = x;
       b = y;
   }
   complex(){
        
       a = 0;
       b = 0;}
    complex(int x){
       a = x;
       b = 0;
   }
    
      
   // void setdatabysum(complex o1, complex o2)
    //{
    //    a = o1.a + o2.a;
      //  b = o1.b + o2.b;
    //}
    void printdata(){
        cout<<"Your complex number is "<<a<<"+"<<b<<"i"<<endl;

    }
};

int main()
{
    complex c1(0);

    c1.printdata();

    return 0;
}
