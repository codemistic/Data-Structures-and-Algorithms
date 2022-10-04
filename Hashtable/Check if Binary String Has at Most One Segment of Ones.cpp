class Solution {
public:
    bool checkOnesSegment(string s) {
        bool changed = false;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) continue;
            if (changed) return false;
            changed = true;
        }
        return true;
    }
};
