class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<string, int> mp;
        mp["1"]++;
        int num = 1;
        while(mp.size() != 30){
            num *= 2;
            string s = to_string(num);
            sort(s.begin(), s.end());
            mp[s]++;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        return (mp.find(s) != mp.end());
    }
};