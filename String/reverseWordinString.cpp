#include <iostream>
using namespace std;

void reverse(string &s, int start, int end){
    if(start>=end) return ;
    swap(s[start],s[end]);
    reverse(s,start+1,end-1);
    }
    
string reverseWords(string s) {
    int start = 0;
    for(int i=0;i<s.length();i++){
        if(s[i+1] == ' ' || s[i+1]=='\0'){
            //Since s[i+1] is space or null character, s[i] is end of a word
            int end = i;
            reverse(s,start,end);
            //Since s[i+1] is space or null character, s[i+2] may be the beginning of new word
            start = i+2;
            }
        }
    reverse(s,start,s.length()-1);
    return s;
    }

int main()
{
    string s,k;
    cout << "Enter The String : ";
    getline(cin, s);
    k=reverseWords(s);
    cout << s << endl;
    cout << k << endl;
}
