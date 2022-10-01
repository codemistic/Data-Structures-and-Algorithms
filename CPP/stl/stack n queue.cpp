#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    stack<int> st;
    st.push(1);
    st.push(3);
    st.push(3);
    st.push(3);
    st.emplace(12);

    cout << st.top() << endl;

    st.pop();

    cout<<st.top()<<endl;

    cout<<st.size()<<endl;

    cout<<st.empty()<<endl;

    //swaping stack 
    stack<int> st1;
    st1.swap(st);
    
    return 0;
}
