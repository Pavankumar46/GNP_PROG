//1
#include <iostream>
#include <memory>
#include <thread>
using namespace std;
class abc
{
  public:
  int val;
  abc(){};
  abc(int a): val(a){}
};
void fun(shared_ptr<abc> a)
{
    static int i=0;
    cout<<a.use_count()<<"  "<<i++<<endl;
}
int main()
{
    shared_ptr<abc>a(new abc(10));
    shared_ptr<abc> b(a),c(a);
    thread t(&fun,a),t1(&fun,b),t2(&fun,c);
    {
        thread t4(&fun,a);
            t4.join();
    }
    t2.join();
    t1.join();
    t.join();
    return 0;
}
-----------------------------------------------------------------------------------------
//2
#include <iostream>
using namespace std;
#include <memory>
 
class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
 
    int area()
    {
        return length * breadth;
    }
};
 
int main()
{
 
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    // This'll print 50
    cout << P1->area() << endl;
 
    shared_ptr<Rectangle> P2;
    P2 = P1;
 
    // This'll print 50
    cout << P2->area() << endl;
 
    // This'll now not give an error,
    cout << P1->area() << endl;
 
    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2
    cout << P1.use_count() << endl;
    return 0;
}