#include<iostream>
using namespace std ;
 int sum(int,int);


 void g();
int main(){



int num1,num2;
cout<<"write the value of num1 "<<endl;
cin>>num1;
cout<<"write the value of num2 "<<endl;
cin>>num2;
cout<<"the sum is equal to "<<" = "<<sum(num1,num2);

g() ;


return 0;
}
int sum(int a,int b){
int c = a + b ;
return c;}
void g(){

cout<<"\nhello good mourning ";

}