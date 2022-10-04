<!-- finding first position of given target using binary search -->

int firstOccur(vector<int>& arr, int n, int k){
    int i=0,j=n-1;
    int finalocc=-1;
    while(i<=j){
        int mid= i+(j-i)/2;
        if(arr[mid]==k){
            finalocc=mid;
            j=mid-1;
        }
        else if(arr[mid]>k){
            j=mid-1;
        }
        else{
            i= mid+1;
        }
    }
    return finalocc;
}
  
<!-- finding last position of target using binary search   -->
int lastOccur(vector<int>& arr, int n, int k){
    int i=0,j=n-1;
    int finalocc=-1;
    while(i<=j){
        int mid= i+(j-i)/2;
        if(arr[mid]==k){
            finalocc=mid;
            i=mid+1;
        }
        else if(arr[mid]>k){
            j=mid-1;
        }
        else{
            i= mid+1;
        }
    }
    return finalocc;
}
  
<!-- function that returns the pair of first and last position of given target   -->
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int ans1= firstOccur(arr,n,k);
    int ans2= lastOccur(arr,n,k);
    return {ans1,ans2};
    
}

