#include<iostream>
using namespace std;
class toy
{
protected:
    string name;
    float price;
public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void applylabel() = 0;
    virtual void showproduct() = 0;
};

class car : public toy
{
    void prepareParts()
    {
        cout<<"preparing car"<<endl;
    }

    void combineParts()
    {
        cout<<"combining car"<<endl;
    }

    void applylabel()
    {
        name = "car";
        price = 10;
    }
    void showproduct()
    {
        cout<<name<<" "<<price<<endl;
    }
};

class bike : public toy
{
    void prepareParts()
    {
        cout<<"preparing bike"<<endl;
    }

    void combineParts()
    {
        cout<<"combining bike"<<endl;
    }

    void applylabel()
    {
        name = "bike";
        price = 10;
    }
    void showproduct()
    {
        cout<<name<<" "<<price<<endl;
    }
};


class toyfactory
{
public:
    static toy * createtoy(int type)
    {
        toy *t = NULL;
        switch(type)
        {
        case 1:t=new car();
            break;

        case 2:t=new bike();
            break;

        default:cout<<"exit";
            return NULL;
            break;
        }
        t->prepareParts();
        t->combineParts();
        t->applylabel();
        return t;
    }
};

int main()
{
    int type;
    while(1)
    {
        cout<<"enter 1 or 2 for toy type, 0 for exit\n"<<endl;
        cin>>type;
        if(type)
        {
            toy *t=toyfactory::createtoy(type);
            if(t)
            {
                t->showproduct();
                delete t;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

