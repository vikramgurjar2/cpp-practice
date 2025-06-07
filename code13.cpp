#include<iostream>
using namespace std;
class Tractor{
    
    private :
    string name ;
    int year;

    //void person(){
        cout<<name;
    //}
    public:
    string company ;
    string horsepower;
    int plateno; 
    void setname(string "name"){
        name="name"   ;
    }
    void getname(){

        return name;
    }

};
//void Tractor :: company{

//}




int main(){
Tractor obj1;
obj1.company = "Johndeer";
obj1.horsepower="55Hp";
obj1.plateno =4708;
obj1.setname( " Jagmohan");
//obj1.year = 2021;


cout<<obj1.company<<" "<<obj1.horsepower<<" "<<obj1.plateno<< "  owner -" <<endl;
obj1.getname();
//person();

Tractor obj2;
obj2.company = "Massy Fergussion";
obj2.horsepower = "35";
obj2.plateno = 43322;
//obj2.name ="Mr. LAL SINGH ";

//cout<<obj2.company<<" "<<obj2.horsepower<<" "<<obj2.plateno<< "  owner - "<< obj2.name <<endl;
//person();








return 0;
}