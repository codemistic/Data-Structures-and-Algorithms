        // this program shows what is difference between structure and union
#include <iostream>
using namespace std;
struct stu
{
    int marks;
    float avg;
    double salary;
};
union stu2
{
    int marks;
    float avg;
    double salary; 
};

int main()
{
    struct stu s;
    union stu2 s2;
    cout<<"Structure size="<<sizeof(s)<<endl;
    cout<<"Union size="<<sizeof(s2);
    
}