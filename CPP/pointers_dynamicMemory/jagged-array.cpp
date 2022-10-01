#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    int n;
    cin>>n;

    // creation of 2array
    //
    int *p= new int [n];
    int **arr= new int *[n];
    for (int i = 0; i < n; i++) {
        cout<<"enter the no of cols in row "<<i<<":";
        cin>>p[i];
    arr[i]= new int[p[i]];

    }
    // taking input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <p[i] ; j++) {
            cin>>arr[i][j];
        }
    }
    // giving the outputl
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i]; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //releasing of all the heap memory
    
    for (int i = 0; i < n; i++) {
        delete [] arr[i];

    }
    delete []arr;
    
    
    return 0;
}


