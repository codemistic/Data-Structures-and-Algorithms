#include <iostream>
using namespace std;
struct stu
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    struct stu s;       // for union we have to change struct keyword into union
    cout<<"enter student roll no: "<<ends;
    cin>>s.roll;
    cout<<"enter student name: "<<ends;
    cin>>s.name;
    cout<<"enter student marks: "<<ends;
    cin>>s.marks;
    cout<<s.roll<<" "<<s.name<<" "<<s.marks;
    return 0;
}