#include<iostream>
using namespace std;

void rotate(int arr[],int n,int d)
{
    int temp[n];
    int j=0;  
    for(int i=d;i<n;i++)
    {
        temp[j]=arr[i];
        j++;
    } 
    for(int i=0;i<d;i++)
    {
        temp[j]=arr[i];
        j++;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
}
void print(int arr[ ],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main()
{
	int n,i,d, arr[10];
	
	cout << "\nPlease Enter the Array Size =  ";
	cin >> n;
    cout<<"enter array elements:"<<endl;
    d=2;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    rotate(arr,n,d);
    print(arr,n);
 	return 0;
}
