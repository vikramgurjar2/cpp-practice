#include <iostream>
using namespace std;
class complex;
//forward class decleration 

class calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int realcomplex(complex, complex);
};

class complex
{  friend class calculator ;
    //friend int calculator ::realcomplex(complex , complex );
    int a, b;

public:
    void setnumber(int v1, int v2)
    {
        v1 = a;
        v2 = b;
    }

    void printnumber(int a, int b)
    {

        cout << "The complex form of equation is " << a << "+" << b << "i" << endl;
    }
};
int calculator :: realcomplex(complex o1, complex o2)
{

    return (o1.a + o2.a);
}

int main()

{
    complex o1, o2;
    o1.setnumber(1, 5);
    o2.setnumber(3, 7);
    calculator calc;
    int res = calc.realcomplex(o1, o2);
    cout << "the sum of real part of o1 and o2 is " << res << endl;

    return 0;
}


























