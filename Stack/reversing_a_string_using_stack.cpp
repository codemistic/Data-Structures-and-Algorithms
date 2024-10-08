#include<bits/stdc++.h>
using namespace std;

/*class Stack{
    private:
    char *arr;
    int size;
    int top=-1;
    public:

    Stack(int n){
        size=n;
        arr=new char[size];
    }

    void push(string t){
        
        if(top==size-1){
            cout<<"stack overflow"<<endl;
        }else{
            top++;
            arr[top]=t[i];
        }
    }
    void display(){
        for(int i=arr.size()-1;i>=0;i--){
            cout<<arr[i];
        }
    }
}*/

int main(){
    
    stack<char> s;
    
    string n =" Saar";
    
    for(int i=0;i<n.size();i++){
        char ch=n[i];
        s.push(ch);
    }
    
    string mac = "";
    
    while(!s.empty()){
        
        char new1=s.top();
        mac.push_back(new1);

        s.pop(); 
    }

    cout<<"answer is"<<mac<<endl;

    return 0;
}