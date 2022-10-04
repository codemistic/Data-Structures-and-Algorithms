#include <iostream>
using namespace std;

// Method 1
bool Palindrome(string s,int start,int end){
    if(start>=end){
        return true;
    }
    return (s[start]==s[end])&&(Palindrome(s,start+1,end-1));
}

// Method 2
void pal(string s){
    int i=0,j=s.length()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            cout<<"String is not Palindrome";
            return ;
        }
        i++,j--;
    }
    cout<<"String is palindrome";
    return ;
}

int main(){
    string s;
    cin>>s;
    cout<<s.length()<<endl;
    cout<<Palindrome(s,0,s.length()-1);
    cout<<endl;
    pal(s);
    
    return 0;
}