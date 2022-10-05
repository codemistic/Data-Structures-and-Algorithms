#include <bits/stdc++.h>
using namespace std;

void reverse(string &str)
{
   stack<char> st;
   for (int i=0; i<str.length(); i++)
       st.push(str[i]);

   for (int i=0; i<str.length(); i++) {
       str[i] = st.top();
       st.pop();
   }      
}

//main function
int main()
{
    string str = "geeksforgeeks";
    reverse(str);
    cout << str;
    return 0;
}
