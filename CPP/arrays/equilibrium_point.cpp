class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        long long total_sum = 0, temp_sum = 0;
        
        for(int i = 0 ; i < n ; i++){
            total_sum += a[i];
        }
        
        for(int i = 0 ; i < n ; i++){
            if(total_sum - temp_sum - a[i] == temp_sum){
                return i + 1;
            }
            temp_sum += a[i];
        }
        return -1;
    }
};
