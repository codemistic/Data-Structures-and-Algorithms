#include <iostream>
using namespace std;
class person
{
    protected:
    string aa;
     public:
    string name;
    int age;
    void get_p()
    {
        cout<<"Enter Name\n";
        cin>>name;
        cout<<"Enter age\n";
        cin>>age;
    }
    void display_p()
    {
        cout<<"Name is "<<name<<"\n";
        cout<<"Age is "<<age<<"\n";
    }

};
class student:public person{
    string courseName;
    int id;
    public:
    void get_s()
    {
        this->get_p();
        cout<<"Enter coursename\n";
        cin>>courseName;
        cout<<"Enter id\n";
        cin>>id;
    }
    void display_s()
    {
        this->display_p();
        cout<<"CourseName is "<<courseName<<"\nid is "<<id<<"\n";
    }
};
// class student
// { public:
// int data;}; // this will work but override above same class
int main()
{
    student *s;
    s=new student();
    if(s->name.empty())
    cout<<"Hello";
    s->get_s();
    s->display_s();
    person p;
    cout<<s->name;
}
