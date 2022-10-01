#include<iostream.h>
using namespace std;
void max(int arr[5])
{
    int max[5];
    max[0]=0;
    int k=0;
    for(int i=0;i<5;i++)
    {
     if(arr[i]>max[k])
       max[k]=arr[i];
    }
    cout<<"maximum number is:"<<max[k];
}
int main(){
    int arr[5],i;
    cout<<"enter members of an array:"<<endl;
    for(i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    max(arr);
    return 0;
}
