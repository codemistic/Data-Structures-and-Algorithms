#include <iostream>
using namespace std;
class a
{
    protected:
    int a,b; 
    public:
       
        void input()
        {
            cout<<"enter two numbers: ";
            cin>>a>>b;
        }
};
class b: public a
{
    int c;
    public:
    void add()
    {
        c=a+b;  
        cout<<"addtion "<<c<<endl;
    }
    void sub()
    {
        c=a-b;
        cout<<"subtraction "<<c<<endl;
    }
};
class c: public b
{
    int c;
    public:
    void multi()
    {
        c=a*b;
        cout<<"multiplication"<<c<<endl;
    }
    void divison()
    {
        c=a/b;
        cout<<"Division"<<c<<endl;
    }
    
};

int main()
{
    c obj;
    obj.input();
    obj.add();
    obj.sub();
    obj.multi();
    obj.divison();

    return 0;
}