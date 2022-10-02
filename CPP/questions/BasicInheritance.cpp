//private inheritance
#include <iostream>
using namespace std;
class person
{
    int id;
    string name;
    public:
    void set_p()
    {
        cout<<"Enter id\n";
        cin>>id;
        cout<<"Enter name\n";
        cin>>name;
        //cout<<name;
    }
    void display()
    {
        cout<<"Name is "<<name<<"\n";
        cout<<"Id is "<<id<<"\n";
    }
};
class Student:private person
{
    string courseName;
    int fee;
    public:
    void get_s()
    {
        set_p();
        cout<<"Enter Course Name\n";
        cin>>courseName;
        cout<<"Enter fee\n";
        cin>>fee;

    }
    void S_display()
    {
        display();
        cout<<courseName<<"\n"<<fee;
    }
};
int main()
{
    Student s;
    s.get_s();
    s.S_display();
}
