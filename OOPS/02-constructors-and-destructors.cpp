// MUST READ : https://www.geeksforgeeks.org/private-destructor/
// MUST READ : https://www.geeksforgeeks.org/can-constructor-private-cpp/

#include <iostream>
using namespace std;

class Student
{
    string name;

public:
    // CONSTRUCTORS
    // have same name as class name
    // automatically called when an object of the class is created
    // can have parameters
    // no return type
    // should be public
    // can be overloaded!

    // default constructor
    Student()
    {
        cout << "called as soon as object of this class is created.";
    }

    // paramaterized constructor
    Student(string name)
    {
        this->name = name;
    }

    // or

    Student(string name) : name(name) {} // another way of initializing

    // DESTRUCTORS
    // called automatically when object goes out of scope or gets destroyed
    // tilde = '~'

    ~Student()
    {
        cout << "object destruction complete!"
             << "\n";
    }
};