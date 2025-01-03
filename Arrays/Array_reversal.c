#include<stdio.h>
#define N 1000

int main(){
    int arr[N];
    
    //giving the size of an array
    int n;
    printf("enter the size of array:\n");
    scanf("%d", &n);

    // Printing the array that will be reversed
    printf("Enter the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    // printing the reversed array
    printf("eversed array:\n");
    for(int i=n-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
    return 0;


}