#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long long a[100000];
    long long n;
    long long c=0,p=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]==-1)
        {c++;          
        }
        else
        {p+=a[i];      
        }       
        if(p<=0)
        {sum++;     
        c--;   
        }
        else if(c!=0)
        {p--;    
        c--;     
        }
    }
    cout<<sum<<endl;
    return 0;

}
