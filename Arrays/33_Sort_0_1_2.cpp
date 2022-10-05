/*

You are given an integer array/list(ARR) of size N. 
It contains only 0s, 1s and 2s. 
Write a solution to sort this array/list in a 'single scan'. 
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once. 
Note: You need to change in the given array/list itself. 
Hence, no need to return or print anything.

Input format : The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list. Output Format : For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line. 
Constraints : 
1 <= t <= 10^2 0 <= N <= 10^5 
Time Limit: 1 sec

Sample Input 1: 1 7 0 1 2 0 2 0 1 
Sample Output 1: 0 0 0 1 1 2 2

Sample Input 2: 2 5 2 2 0 1 1 7 0 1 2 0 1 2 0 
Sample Output 2: 0 1 1 2 2 0 0 0 1 1 2 2

*/
#include<iostream>
using namespace std;

void simplifiedsort012(int *arr, int n){

    int i=0,nz=0,nt=n-1;
    while(i<n &&i<=nt){
        if(arr[i]==0){
              int temp=arr[i];
            arr[i]=arr[nz];
            arr[nz]=temp;
            nz++;
        }
        else if(arr[i]==2){
                int temp=arr[i];
            arr[i]=arr[nt];
            arr[nt]=temp;
            nt--;
            continue;

        }

        i++;
    }
}

int main(){

    int n;
    cout<<"Enter the size of the Array "<<endl;
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter Elements in the Array "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    simplifiedsort012(arr,n);
    return 0;
}

/*
Explanation
👉🏼Take two variables as starting(nz) and ending(nt) depicting position of 0's and 2's to be swapped respectively

👉🏼Initialize nz as Starting Index i.e 0 and increment it after every swap

👉🏼Initialize nt as Ending Index i.e Size-1 and decrement it after every swap

Special Attention should be given to the following points :)
✨Swap 0's and increment nz & i

✨Swap 2's and increment nt but not i (ignore the updation of expression)
*/