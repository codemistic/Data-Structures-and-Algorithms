class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int target) {
        long h = 0, N = s.size(), pp = 1; // `pp` = p^k
        vector<long> hash(N);
        string r(rbegin(s), rend(s));
        for (int i = 0; i < N; ++i) {
            if (i < k) pp = pp * p % mod;
            h = (h * p + (r[i] - 'a' + 1)) % mod; // push r[i] into the window
            if (i - k >= 0) { // pop r[i-k] out of the window
                h = (h - (r[i - k] - 'a' + 1) * pp % mod + mod) % mod;
            }
            if (i >= k - 1) hash[i] = h;
        }
        reverse(begin(hash), end(hash));
        for (int i = 0; i < N; ++i) {
            if (hash[i] == target) return s.substr(i, k); // hash[i] is the hash of `s[i .. (i+k-1)]`
        }
        return "";
    }
};
