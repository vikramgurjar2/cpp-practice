#include <iostream>
using namespace std;
class complex
{
    int a;
    int b;

public:
    void setdata(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    /*void setdatabysum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }*/
    void printdata()
    {
        cout << "Your complex number is " << a << "+" << b << "i" << endl;
    }
    complex(int x, int y)
    {
        a = x;

        b = y;
    }
};

int main()
{
    // implicit call
    complex w(3, 5);
    w.printdata();
    // explicit call
    complex r = complex(7, 8);
    r.printdata();

    return 0;
}