#include <iostream>
using namespace std;

class Bankdeposite
{
    int principle;
    int year;
    float interest;
    float returnvalue;

public:
    Bankdeposite(){};
    Bankdeposite(int p, int y, float r);
    // Bankdeposite(int p,int y ,int r);

    void displayvalue();
};

Bankdeposite ::Bankdeposite(int p, int y, float r)
{
    p = principle;
    y = year;
    r = interest;
    returnvalue = principle;
    for (int i = 0; i < y; i++)
    {

        returnvalue = returnvalue * (1 + interest);
    }
}
Bankdeposite ::Bankdeposite(int p, int y, int r)
{
     year = y;
     interest = float(r)/100;
     principle = p;
    returnvalue = principle;
    for (int i = 0; i < y; i++)
    {

        returnvalue = returnvalue * (1 + interest);
    }
}
void Bankdeposite ::displayvalue()
{

    cout << "The principle value is " << principle
         << ".THe interest rate is " << interest
         << ",in year " << year << "is " << returnvalue;
}

int main()
{
    Bankdeposite B1, B2, B3;
    int p;
    float r;
    int y;
    cout << "write the value of p,y,r" << endl;
    cin >> p >> y >> r;
    B1 = Bankdeposite(p, y, r);
    B1.displayvalue();

    return 0;
}
