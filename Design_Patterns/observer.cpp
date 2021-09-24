#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class observer;
class car
{
    int position;
    int tmp;
    vector<class observer*> observerlist;
public:
    int getposition()
    {
        return position;
    }
    void setposition(int pos)
    {
        position = pos;
        notify();
    }
    void attach(observer *obs)
    {
        observerlist.push_back(obs);
    }
    void detach(observer *obs)
    {
        observerlist.erase(std::remove(observerlist.begin(), observerlist.end(), obs), observerlist.end());
    }
    void notify();


};

class observer
{
    car *c;
public:
    observer(car *c1)
    {
        c=c1;
        c->attach(this);
    }
    virtual void update()=0;
protected:
    car *getcar()
    {
        return c;
    }
};
void car::notify()
 {
        for(int i=0;i<observerlist.size();i++)
        {
            observerlist[i]->update();
        }
    }

class leftcar : public observer
{
        public:
    leftcar(car *c):observer(c){}
    void update()
    {
        int pos=getcar()->getposition();
        if(pos == 0)
        {
            cout<<"left"<<endl;
        }
    }
};


class middlecar : public observer
{
    public:
    middlecar(car *c):observer(c){}
    void update()
    {
        int pos=getcar()->getposition();
        if(pos < 0)
        {
            cout<<"middle"<<endl;
        }
    }
};

class rightcar : public observer
{
        public:
    rightcar(car *c):observer(c){}
    void update()
    {
        int pos=getcar()->getposition();
        if(pos > 0)
        {
            cout<<"right"<<endl;
        }
    }
};

int main()
{
    car *c =new car();

    leftcar l(c);
    rightcar r(c);
    middlecar m(c);
    char op;
    bool b=false;
    while(b == false)
    {
        cin>>op;
        switch(op)
        {
        case 108 :c->setposition(0); // l
            break;
        case 99 :c->setposition(-1);//c
            break;
        case 114 :c->setposition(1);//r
            break;
        default:cout<<"gone"<<endl;
            b=true;
            break;
        }

    }


}













