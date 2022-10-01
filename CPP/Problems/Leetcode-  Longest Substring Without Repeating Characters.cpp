class Solution {
public:
    int lengthOfLongestSubstring(string str) {
    if(str.size()==0)return 0;
       int left=0, right=0, n=str.size(), mx=0;
        set<int>st;
        while(right<n){
            if(st.count(str[right])==0){
                 st.insert(str[right]);
                mx=((int)st.size()>mx)?st.size():mx;
                right++;
            }else{
                st.erase(str[left]);
                left++;
            }
        }
        return mx;
    }
};
