#include <bits/stdc++.h>
using namespace std;

int FoundPivot(int arr[],int l,int r){
    if(l<=r){
        int mid = l + (r-l)/2;

        if(mid<r && arr[mid]>arr[mid+1])
        return mid;
        else if(mid > l && arr[mid] < arr[mid-1])
        return mid-1;

        if(arr[mid] >= arr[r])
        return FoundPivot(arr, mid+1, r);

        else
        return FoundPivot(arr, l, mid-1);

    }
    return -1;
}
int binarySearch(int arr[], int l, int r, int target){
    if(l>r)return -1;

    int mid = l + (r-l)/2;

    if(arr[mid] > target){
        return binarySearch(arr,l, mid-1, target);
    }
    else if(arr[mid] < target){
        return binarySearch(arr, mid+1, r, target);
    }
        return mid;
}

void searchElementInRotatedArray(int arr[], int target,int n){
    int pivot = FoundPivot(arr,0, n-1);

    if(pivot == -1)return;

    int found = binarySearch(arr, 0, pivot, target);
    
    if(found == -1){
        found = binarySearch(arr, pivot+1, n-1, target);
    }
    if(found == -1){
      cout<<"NOT PRESENT !!";
      return;
    }
     cout<<"FOUND AT :"<<found;
}

int main(){
    int arr[] = {110,130,140,170,10,20,30,50,60,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 30;
    searchElementInRotatedArray(arr, target,n);


}