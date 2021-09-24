#include <iostream>
using namespace std;
 
// A generic smart pointer class
class abc
{
    public:
        int a;  
};
class bcd
{
    public:
        int b;
};
template <class T>
class SmartPtr {
    T* ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferncing operator
    T& operator*() { return *ptr; }
 
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};
 
int main()
{
    SmartPtr<abc> ptr(new abc());
    ptr->a = 20;
    cout << ptr->a<<endl;
    SmartPtr<bcd> ptr1(new bcd());
    ptr1->b = 20;
    cout << ptr1->b;
    return 0;
}