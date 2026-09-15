#include<iostream> 
using namespace std; 
 class Complex 
{
    private: 
    int real; 
    int imag; 
    public: 
    Complex ( void ) = delete; // C++ 11  (IMP) we cannot create  obj without passing valeu to parameterized ctor
    Complex(int real , int imag) //double value parameterized ctor 
    {
        cout<<"Complex(int value)"<<endl;  
        this->real = real; 
        this->imag = imag; 
    }
    void acceptRecord( void )
    {
        cout<<"Real : "; 
        cin>>real; 
        cout<<"Imag : "; 
        cin>>imag; 
    }
    void printRecord( void )
    {
        cout<<"Real : "<<real<<endl;
        cout<<"imag : "<<imag<<endl; 
    }
}; 
int main()
{
    //Complex c1;
    Complex c1(10,20); 
    return 0;
}

