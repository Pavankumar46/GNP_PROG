#include<iostream>
#include<stdlib.h>
using namespace std;
class tyre
{

    string name;
    int pressure;
    public:
    tyre(string n,int val):name(n),pressure(val){}
    string getname()
    {
        return name;
    }
    int getpressure()
    {
        return pressure;
    }
};


class simpletyre : public tyre
{
    public:
    simpletyre():tyre("simpletyre",3){}
};
class luxtyre : public tyre
{
    public:
    luxtyre():tyre("luxtyre",6){}
};

class body
{

    string name;
    int strength;
    public:
    body(string n,int val):name(n),strength(val){}
    string getname()
    {
        return name;
    }
    int getstrength()
    {
        return strength;
    }
};


class simplebody : public body
{
    public:
    simplebody():body("simplebody",2){}
};
class luxbody : public body
{
    public:
    luxbody():body("luxbody",4){}
};

class car
{
    string name;
    tyre *t;
    body *b;
    public:
    car(string n):name(n){}
    void setTire(tyre *tyre){t = tyre;}
    void setBody(body *body){b = body;}
    void printdetails()
    {
        cout<<endl<<name<<endl;
        cout<<t->getname()<<" "<<t->getpressure()<<endl;
        cout<<b->getname()<<" "<<b->getstrength()<<endl;

    }
};

class carfactory
{
    car *c;
public:
    virtual car * buildcar() = 0;
};

class simplecarfactory : public carfactory
{
    tyre * buildtyre(){return new simpletyre();}
    body * buildbody(){return new simplebody();}
    car * buildcar()
    {
        car *car1 = new car("simplecar");
        car1->setTire(buildtyre());
        car1->setBody(buildbody());
        return car1;
    }
};

class luxcarfactory : public carfactory
{
    tyre * buildtyre(){return new luxtyre();}
    body * buildbody(){return new luxbody();}
    car * buildcar()
    {
        car *car1 = new car("luxcar");
        car1->setTire(buildtyre());
        car1->setBody(buildbody());
        return car1;
    }
};

#define SIMPLE_CAR 1


int main()
{
#if SIMPLE_CAR
    carfactory *factory = new simplecarfactory;
#else
    carfactory *factory = new luxcarfactory;
#endif
    car *car = factory->buildcar();
    car->printdetails();
}

