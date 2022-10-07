// { Driver Code Starts
// C++ program to print sum triangle for a given array
#include <bits/stdc++.h>
using namespace std;

vector<long long> getTriangle(int arr[], int n);

// Driver Program
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        
        vector<long long> Triangle = getTriangle(a, n);
        
        for(auto it: Triangle)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> getTriangle(int a[], int n)
{
    vector< long long> oof(a,a+n);
    if(n==1){
     return oof;
        
    }

    else
        {
            int curr=n-1;
            
            reverse(oof.begin(),oof.end()); //7,6,3,7,4
            int beg=0, in=n;
            int i;
            while(beg!=in){
                for(i=beg;i<in-1;i++){
                  
                oof.push_back(oof[i] + oof[i+1]);
                }
                
                beg=i+1;in+=curr;curr--;
            }
            }

    reverse(oof.begin(),oof.end());
    
    return oof;
}