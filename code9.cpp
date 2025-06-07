#include<iostream>
using namespace std;
//void variablename( ){

//"hello world "
//}
tablefunction( int a   ){
    for(int i = 1;i<11;i++){
      cout<<a*i<<endl;

    }


}
void namefunction( string fname ,int age){

    cout<<fname<<"  "<<age <<" "<<" year old";

}
int n;
//function of prime number less than n
primefunction(int a){
    for(int i=0;i<a;i++){
    if(i%n != 0){ 
        
        if(i==n){
          i++;
          continue;}
          cout<<i<<endl;
          i++;
    }



    }



}





int main(){ 
    //tablefunction(33);

//namefunction("kartik",22);

primefunction(20);












return 0;


}