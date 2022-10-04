class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> mp;
        for(int i=0;i<sentence.length();i++)
        {
            mp[sentence[i]]++;
        }
        for(char i='a';i<='z';i++)
        {
            if(mp[i]==0) return false;
        }
        return true;
        
    }
};