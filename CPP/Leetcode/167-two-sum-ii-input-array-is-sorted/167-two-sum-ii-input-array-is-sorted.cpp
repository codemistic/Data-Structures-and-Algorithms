class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> v;
        while(i<j)
        {
            int k=numbers[i]+numbers[j]; 
            if(k==target)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            if(k<target)
            {
                i++;
            }
            else j--;
        }
        return v;
    }
};