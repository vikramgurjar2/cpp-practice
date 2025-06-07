// this is a program for getting the distance between two points using constructor and math function
#include <iostream>
#include <math.h>

using namespace std;
class point
{
    int x, y;

public:
    friend int distance(point o1, point o2);
    point(int, int);
    void display()
    { // we can define the constructor here also
        cout << "the point are (" << x << " , " << y << ")" << endl;
    }
};
point ::point(int a, int b)
{
    x = a;
    y = b;
}
int distance(point o1, point o2)
{
    float c;
    c = sqrt(pow((o2.x - o1.x), 2) + pow((o2.y - o1.y), 2));
    // dis = sqrt(pow((obj2.x - obj1.x), 2) + pow((obj2.y - obj1.y), 2));
    return c;
}
int main()
{
    point q(4, 5);
    q.display();
    point s(8, 2);
    s.display();
    distance(q, s);
    cout << "the distance between these two points are " << distance(q, s) << endl;
    return 0;
} // this is a prog