#include<iostream> 
using namespace std; 
class Base 
{
    private: 
    int *bptr; 
    public: 
    Base ( void )
    {
        cout<<"Base class ctor called"<<endl; 
        bptr = new int[3]; 
    }
    virtual ~Base( void )
    {
        cout<<"Base class dtor called"<<endl; 
        delete[] bptr; 
        bptr = NULL; 
    }
// Due to early binding, when the object pointer of the Base class is deleted, which was pointing to the
// object of the Derived class then, only the destructor of the base class is invoked
// It does not invoke the destructor of the derived class, which leads to the problem of memory leak in
// our program and hence can result in undefined behavior.
// To correct this situation, the base class should be defined with a virtual destructor.
}; 
class Derived : public Base 
{
    private: 
    int *dptr; 
    public: 
    Derived( )
    {
        cout<<"Derived class ctor called"<<endl; 
        dptr = new int[3]; 
    }
    ~Derived( )
    {
        cout<<"Derived class dtor called"<<endl; 
        delete[] dptr;
        dptr = NULL;   
    }
}; 
int main()
{
    Base *ptrBase = new Derived( ); 
    delete ptrBase; 
    return 0;
}

int main2()
{
    Derived *ptrDerived = new Derived( ); 
    delete ptrDerived; 
    return 0;
}

int main1()
{
    Base *ptrBase = new Base( ); 
    delete ptrBase; 
    return 0;
}
