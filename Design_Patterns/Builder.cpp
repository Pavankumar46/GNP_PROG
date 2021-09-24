// Question: WHY Builder Design Pattern
// Answer  : Because i want to build an object(plane) and it is compossed of complex
//           objects(body, engine) step by step.


#include<iostream>
using namespace std;
class plane
{
    string p;
    string body;
    string engine;
public:
    plane(string name):p(name){}
    void setengine(string s)
    {
        engine = s;
    }
    void setbody(string s)
    {
        body = s;
    }
    void show()
    {
        cout<<"plane type  "<<p<<endl<<"body type  "<<body<<"engine type  "<<engine<<endl;
    }
};
class planebuilder
{
protected:
    plane *p;
public:
    virtual void getparts()=0;
    virtual void buildbody()=0;
    virtual void buildengine()=0;
    plane * getplane()
    {
        return p;
    }
};

class type1 : public planebuilder
{
    void getparts()
    {
        p = new plane("type1\n");
    }

    void buildbody()
    {
        p->setbody("type 1 body\n");
    }

    void buildengine()
    {
        p->setengine("type 1 engine\n");
    }

};
class type2 : public planebuilder
{
    void getparts()
    {
        p = new plane("type2\n");
    }

    void buildbody()
    {
        p->setbody("type 2 body\n");
    }

    void buildengine()
    {
        p->setengine("type 2 engine\n");
    }

};

class dir
{
protected:
    planebuilder *pb;
public:
    plane * createplane(planebuilder *type)
    {
        type->getparts();
        type->buildbody();
        type->buildengine();
        return type->getplane();
    }

};

int main()
{
    dir d;
    type1 t1;
    type2 t2;

    plane *jet = d.createplane(&t1);
    plane *pro = d.createplane(&t2);
    jet->show();
    pro->show();
    delete jet;
    delete pro;
    return 0;
}

