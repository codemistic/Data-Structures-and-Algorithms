bool cmp(string &a, string &b){
    return a.length() < b.length();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        map<string, int> mp;
        int ans = 0;
        for(auto word: words){
            int cur = 0;
            for(int i=0;i<word.length(); i++){
                string prev = word.substr(0,i)+word.substr(i+1);
                cur = max(cur, mp[prev]+1);
            }
            mp[word] = cur;
            ans = max(ans, cur);
        }

        return ans;
    }
};