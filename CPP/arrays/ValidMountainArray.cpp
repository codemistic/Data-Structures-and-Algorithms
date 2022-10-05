class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        
        int i = 0;
        for(;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i+1])
               { i++;
                break;
                }
            else if(arr[i]==arr[i+1]) return false;
        }
        if(i<2) return false;
        for(;i<arr.size();i++)
        {
            if(arr[i-1]<=arr[i])
                return false;
        }
        return true;
    }
    
};