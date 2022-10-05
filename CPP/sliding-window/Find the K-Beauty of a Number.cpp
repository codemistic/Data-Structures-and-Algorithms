class Solution {
public:
    bool isBeauty(string s1, string s2){
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        if(n2) return !(n1 % n2);
        return false;
    }
    
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        if(!n) return 0;
        int i = 0, j = 0, beautyCount = 0;
        
        
        while(j < n){
            // Calculation
            string window = s.substr(i, j - i + 1);
            
            // Window size not reached yet
            if(j - i + 1 < k){
                j++;
            }
            
            else if(j - i + 1 == k){
                // Find the answer
                if(isBeauty(s, window)) beautyCount++;
                
                // Slide the window
                i++;
                j++;
            }
        }
        return beautyCount;
    }
};
