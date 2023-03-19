#include <iostream>
using namespace std;
// code reusability
// child class is derived from parent (base) class
// child class can access properties of the base class

// Single level inheritance
// Class B inherits from class A

class Teacher
{
public:
    Teacher()
    {
        cout << "Teacher constructor called! \n";
    }
    ~Teacher()
    {
        cout << "Teacher destructor called! \n";
    }
};

class MathTeacher : public Teacher
{
public:
    MathTeacher()
    {
        cout << "MathTeacher constructor called! \n";
    }
    ~MathTeacher()
    {
        cout << "MathTeacher destructor called! \n";
    }
};

int main()
{
    MathTeacher Ramesh;
    // OUTPUT!
    // Teacher constructor called!
    // MathTeacher constructor called!
    // MathTeacher destructor called!
    // Teacher destructor called!
    return 0;
}