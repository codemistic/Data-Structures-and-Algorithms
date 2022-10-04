class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]]>0 && mp[arr[i]*2]>0 && arr[i]!=0) return true;
            if(mp[arr[i]]>=2 && arr[i]==0) return true;
        }
        return false;
        
    }
};