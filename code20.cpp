#include<iostream>
using namespace std;
class complex {

int a,b;
public: 
void setdat(int v1 ,int v2){
a=v1 ;
b= v2; 
}
void getdata(void ){
    cout<<"the value of a and b are "<<a<<","<<b<<endl;
}
complex(void); 
};

complex :: complex(){
a= 33;
b = 3;

}





int main(){
complex h1;
h1.getdata();

return 0;
}