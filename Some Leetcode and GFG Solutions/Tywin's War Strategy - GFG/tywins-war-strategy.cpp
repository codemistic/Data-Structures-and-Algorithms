// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int min_soldiers(int arr[], int n, int k);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n, k;
        cin>> n >> k;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        cout << min_soldiers(arr, n, k) << endl;
        
    }
	
	return 0;
}// } Driver Code Ends


int min_soldiers(int a[], int n, int k){
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%k==0)x++;
        else y++;
    }
    if(x>=y)return 0;
   
    int oof=0;
    vector<int> sheesh;
    
    for(int i=0;i<n;i++)
    {
        if(x>=y)break;
        
        if(a[i]%k!=0)
        {
            sheesh.push_back(k-(a[i]%k));
        }
    }
        sort(sheesh.begin(),sheesh.end());
        for(int i=0;i<=sheesh.size();i++)
        {
            if(x>=y)break;
            oof+=sheesh[i];
            x++;y--;
        }
    return oof;
        
    
}