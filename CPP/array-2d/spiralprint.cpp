#include <bits/stdc++.h>
using namespace std;
        
#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'
void spiral(int arr[][10],int n,int m){
    int startRow=0;
    int endRow=n-1;
    int startCol=0;
    int endCol=m-1;

    //outer loop
    while(startCol<=endCol and startRow<=endRow){
        //start row
        for(int col=startCol;col<=endCol;col++){
             cout<<arr[startRow][col]<<" ";
        }
        //end col
        for(int row=startRow+1;row<=endRow;row++){
            cout<<arr[row][endCol]<<" ";
        }
        //end row
        for (int col=endCol-1;col>=startCol;col--) {
                       if(startRow==endRow){
                break;
            }
            cout<<arr[endRow][col]<<" ";

        }
        for(int row=endRow-1;row>=startRow+1;row--){
            if(startCol==endCol){
                break;
            }
            cout<<arr[row][startCol]<<" ";
            
        }
        startRow++;
        startCol++;
        endRow--;
        endCol--;
    }   
}
int main(){
    int n=4;
    int m=4;
    int arr[][10] = { {1, 2, 3, 4},{12, 13, 14, 5},{11, 16, 15, 6},{10, 9, 8, 7}};
    
    spiral(arr,n,m);
        
         
        
        
    return 0;
}       



