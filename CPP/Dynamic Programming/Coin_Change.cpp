// Question.
/*

Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[].  

Note: Assume that you have an infinite supply of each type of coin. 

Examples: 

    Input: sum = 4, coins[] = {1,2,3}, 
    Output: 4
    Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}. 

    Input: sum = 10, coins[] = {2, 5, 3, 6}
    Output: 5
    Explanation: There are five solutions: 
    {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.

*/

// Code. using the DP approach and using memoization.

#include<bits/stdc++.h>
using namespace std;

int Count_Coins(int coins[],int n,int sum){
    int table[sum+1];
    memset(table,0,sizeof(table));
    table[0]=1;

    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=sum;j++){
            table[j]+=table[j-coins[i]];
        }
    }
    
    return table[sum];
}

int main(){
    
    int coins[]={1,2,3};
    int n=sizeof(coins)/sizeof(coins[0]);
    int sum=4;
    cout<<Count_Coins(coins,n,sum);
    
    return 0;
}
