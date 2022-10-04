class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 2*n-1; i > -1; i--){
            while(!st.empty() and nums[i%n] >= st.top()){
                st.pop();
            }
            if(i < n){
                if(!st.empty())
                    res[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};