class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(n, -1);
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++){
            int val = nums2[i];
            while(!st.empty() and val > st.top()){
                mp[st.top()] = val;
                st.pop();
            }
            st.push(val);
        }
        for(int i = 0; i < n; i++){
            int val = nums1[i];
            if(mp.find(val) != mp.end()){
                int nge = mp[val];
                res[i] = nge;
            }
        }
        return res;
    }
};