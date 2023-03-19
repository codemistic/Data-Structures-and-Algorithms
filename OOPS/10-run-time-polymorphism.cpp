// Run-Time Polymorphism
// Dynamic Polymorphism
// Dynamic or Late binding

// Example ->
// 1. Function Over-riding

#include <iostream>
using namespace std;

class Person
{
public:
    void display()
    {
        cout << "Super class function!";
    }
};

class Teacher : public Person
{
public:
    void display()
    {
        cout << "Derived class function!";
    }
};

int main()
{
    Person P;
    Teacher T;

    T.display(); // function over-riding
}

// since Teacher is inheriting from the Person class which already has 'display()' function,
// There will be 2 display functions in Teacher class, however, when we call Teacher.display()
// The display function in Teacher class overrides the super class function
// This is called over-riding and is an example of run-time polymorphism