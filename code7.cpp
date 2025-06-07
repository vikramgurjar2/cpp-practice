#include<iostream>
using namespace std;
int main(){


//string car[4] = {"volvo","mercedies","bmw","xuv"  };
//for(int i = 0;i<6;i++){

  //  cout<<car[i]<<endl;
//}

struct 
{ string brand ;
  string model;
  int year;
}car1,car2;


//car 1 data 
car1.brand = "bmw" ;
car1.model  = "X5";
car1.year = 2022;
//car2 data

car2.brand ="mercidies" ;
car2.model=  " benz    ";
car2.year = 2021  ;

cout<<car1.brand<<" "<<car1.model<<" "<<car1.year<<endl;
cout<<car2.brand<<" "<<car2.model<<" "<<car2.year;
return 0;


}