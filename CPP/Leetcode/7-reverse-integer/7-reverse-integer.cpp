class Solution {
public:
    int reverse(int x) {
        int cnt=0;
        while(x!=0)
        {
            int d=x%10;
            if(cnt>INT_MAX/10 || cnt<INT_MIN/10) return 0;
            cnt=cnt*10 + d;
            x=x/10;
        }
        return cnt;
    }
};