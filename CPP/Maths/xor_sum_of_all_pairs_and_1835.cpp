class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int a = 0, b = 0;
        for(auto i : arr1)
            a = a ^ i;
        for(auto j : arr2)
            b = b ^ j;
        return a & b;
    }
};