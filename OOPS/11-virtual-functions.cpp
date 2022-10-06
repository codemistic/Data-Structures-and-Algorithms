// Virtual Functions
// base class can access child class functions
// RUN TIME POLYMORPHISM

// A virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class.
// When you refer to a derived class object using a pointer or a reference to the base class,
// you can call a virtual function for that object and execute the derived class’s version of the function.

// Virtual functions allow us to create a list of base class pointers
// and call methods of any of the derived classes without even knowing kind of derived class object.

// IMP -> https://www.geeksforgeeks.org/c-plus-plus-gq/virtual-functions-gq/
#include <iostream>
using namespace std;

class BaseClass
{
public:
    virtual void print()
    {
        cout << "BASE CLASS PRINT FUNCTION \n";
    }
    void show()
    {
        cout << "BASE CLASS SHOW FUNCTION \n";
    }
};

class DerivedClass : public BaseClass
{
public:
    void print()
    {
        cout << "DERIVED CLASS PRINT FUNCTION \n";
    }
    void show()
    {
        cout << "DERIVED CLASS SHOW FUNCTION \n";
    }
};

int main()
{
    BaseClass *bptr = new DerivedClass();
    bptr->show();  // will access show function in base class
    bptr->print(); // will access derived class' print function as print is virtual in base class
    return 0;
}