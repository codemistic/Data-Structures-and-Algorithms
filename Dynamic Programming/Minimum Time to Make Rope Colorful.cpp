//problem statement https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
class Solution {
public:
    int minCost(string c, vector<int>& nT) {
        int n=c.size();
        int sum=0;
        int mx=nT[0];
        for(int i=1;i<=n;i++){
            if(c[i]==c[i-1]){
                sum+=min(nT[i-1],nT[i]);
                nT[i]=max(nT[i],nT[i-1]);
            }
        }
        return sum;
    }
};
