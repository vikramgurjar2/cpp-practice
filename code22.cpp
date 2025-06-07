#include <iostream>
#include<cmath>
using namespace std;
class point
{friend int  distance(point p1 ,point p2);
    int a, b;

public:
 point(int x,int y){
     a = x;
     b = y;
 }
void  displaypoint(){
    cout<<"The point is "<<"("<<a<<","<<b<<")"<<endl;

 }
};
int distance(point p1,point p2){
float d;
d = sqrt(pow((p1.a-p2.a),2)+pow((p1.b-p2.b),2));
return d;
}






int main()
{
point p1(2,3);
p1.displaypoint();

point p2(2,78);
p2.displaypoint();
cout<<"the distance between the points p1,p2 is "<<distance(p1,p2)<<endl; 
    return 0;
}