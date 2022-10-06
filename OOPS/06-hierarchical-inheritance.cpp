#include <iostream>
using namespace std;

// Hierarchical inheritance
// Class B and C inherits A

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

class FirstGradeTeacher : public Teacher
{
public:
    FirstGradeTeacher()
    {
        cout << "FirstGradeTeacher constructor called! \n";
    }
    ~FirstGradeTeacher()
    {
        cout << "FirstGradeTeacher destructor called! \n";
    }
};

int main()
{
    FirstGradeTeacher Ramesh;
    // OUTPUT!
    // Teacher constructor called!
    // FirstGradeTeacher constructor called!
    // FirstGradeTeacher destructor called!
    // Teacher destructor called!
    return 0;
}