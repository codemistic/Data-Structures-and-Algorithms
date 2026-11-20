#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int str_len;
	   string str;
	   cin>>str_len>>str;
	   
	   int counter=0;
	   for(int i=0;i<str.length();i++){
	       if(str[i]==str[i+1])
	            counter++;
	    //    else
	    //        // counter--;
	    //         i++;
		else
			continue;
	   }
	   cout<<counter<<endl;
	}
	return 0;
}
