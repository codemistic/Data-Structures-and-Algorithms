#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    /*
    //setting the size of vector
     vector<int> arr(5);
     cout<<"the size of vector is :" <<arr.size();
     */
    /*
    //initialising the vetor with the same value
     vector<int> arr(5,21);
     for (auto i : arr) {
         cout<<i<<" ";
     }
     */
    //if we add an extra element in the vector the size of that vector doubles
    //using the find function ind vector 
     vector<int> arr={1,33,23,4,5,6};
     int key;
     cin>>key;
     vector<int> ::iterator it= find(arr.begin(),arr.end(),key);
     if(it!=arr.end()){
         cout<<"preset at index "<<it-arr.begin();
     }
     else{
         cout<<"not present"<<endl;
     }

    return 0;
}


