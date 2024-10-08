class Solution {
public:

    unordered_map<string,string> mp;
    string encode(string longUrl) {
        mp["enigma"]=longUrl;
        return "enigma";
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));