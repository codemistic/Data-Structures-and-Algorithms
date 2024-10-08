class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>  v;
        sort(changed.begin(),changed.end());
        map<int,int> mp;
        for(int i=0;i<changed.size();i++)
        {
            mp[changed[i]]++;
        }
        
        int n=changed.size();
        int cnt=0;
        if(n%2) return {};
        for(int i=0;i<changed.size();i++)
        {
           if (mp[changed[i]] == 0) continue;
          if (mp[changed[i] * 2] == 0) return {};
          v.push_back(changed[i]);
          mp[changed[i]]--;
          mp[changed[i] * 2]--;
        }
        return v;
        
        
    }
};