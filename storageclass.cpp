#include <iostream>
using namespace std;
void fun()
{
    int a=10;
    static int b=10; //once value is assign then it cannot be change
    cout<<a<<" "<<ends<<b<<endl;
    ++a; ++b;
}
int main()
{
    fun();
    fun();
    fun();
    fun();
    fun();
    return 0;   
}