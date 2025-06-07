#include <iostream>
using namespace std;

class Employee
{
    int Id;
    static int count;

public:
    // void initcount(count )
    void setdata()
    {

        cout << "Enter the Id of employee " << endl;
        cin >> Id;
        count++;
    }
    void getdata(void)
    {
        cout << "The employee Id is" <<"  "<< Id << "  "<<"of employee no" << count << endl;
    }
};
int Employee ::count; // defoult value is zero

int main()
{
    Employee harry, rohan, sahil;
    harry.setdata();
    harry.getdata();
    rohan.setdata();
    rohan.getdata();
    sahil.setdata();
    sahil.getdata();
    return 0;
}