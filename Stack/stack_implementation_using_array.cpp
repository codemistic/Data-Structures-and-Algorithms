#include <bits/stdc++.h>
using namespace std;

class stack1
{
private:
    int size;
    int top;
    vector<int> s;    

public:
    stack1(int n){
        size=n;
        s.resize(n);
        top=-1;
    }

        void display()
        {
            int i;
            for (i = top; i >= 0; i--)
            {
                cout<<s[i]<<endl;
            }
        }

        void push(int x)
        {
            if (top == size - 1)
            {
                cout<<"Stack Overflow"<<endl;
            }
            else
            {
                top++;
                s[top] = x;
            }
        }

        int pop()
        {
            int x = -1;
            if (top == -1)
            {
                cout<<"Stack Underflow"<<endl;
            }
            else
            {
                x = s[top--];
            }
            return x;
        }
    };

int main()
{
    stack1 st(4);
    

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    
    st.display();
    return 0;
}