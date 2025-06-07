#include <iostream>
using namespace std;
class Employee
{

public:
    float salery;
    int Id;
    //Employee(int Inpid)
    //{    Inpid = Id;
      //  salery = 200000;
        //cout << "The employee of id number " << Id << "  "
          //   << "have monthly saliry around " << salery << endl;
   // }
};

class developer : public Employee
{  public:
    
 //Sfloat salery = 200000;
    developer(int Inpid)
    {Inpid = Id;
        //salery = 200000;
        cout << "The employee of id number " << Id << "  "
             << "have monthly saliry around " << salery << endl;
    }
    };

    int main()
    {
        developer harry(23);
        return 0;
    }