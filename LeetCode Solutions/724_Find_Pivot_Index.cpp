class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2(nums.size());
        arr1.push_back(0);
        arr2[nums.size()-1] = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            arr1.push_back(nums[i] + arr1[i]);
        }
        for(int i = nums.size() - 1; i > 0; i--){
            arr2[i-1] = arr2[i] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(arr1[i] == arr2[i]){
                return i;
            }
        }
        return -1;
    }
};
