#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    /*12
    cout<<"2nd element ="<<arr[1]<<" address of 2nd "<<arr+1<<endl;
    int arr[3]={1,2,3};
    cout<<"1st element ="<<arr[0]<<" address of 1st "<<arr<<endl;
    cout<<"address of 1st "<<&arr[0]<<endl;
    cout<<"2nd element ="<<arr[1]<<" address of 2nd "<<arr+1<<endl;
    cout<<"3rd element ="<<arr[2]<<" address of 2nd "<<arr+2<<endl;
    int *ptr=&arr[0];
    cout<<ptr<<" "<<*ptr<<endl;
    // arr[i]==*(arr+i)
    cout<<arr[1]<<"-"<<*(arr+1)<<endl;
    cout<<1[arr]<<"-"<<*(1+arr)<<endl;
    */
    /*
    int arr[3]={23,24,21};
    int *ptr =&arr[0];
    cout<<ptr<<endl;
    ptr=ptr+1;
    cout<<ptr<<endl;
    */

    /*
    char ch[5]="abcd";
    cout<<ch<<endl;//this will output the content of ch not the address
    char *ct= &ch[0];
    cout<<ct<<endl;//this will also print entire char array
                   //cout is different for int array and char array
    char temp='f';
    char *p=&temp;
    cout<<p<<endl;//it will print until it get a NULL char
     */
    char s[]= "hello";
char *p = s;
cout << s[0] << " " << p[0];
    return 0;
}


