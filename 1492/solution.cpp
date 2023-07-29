class Solution {
public:
    int kthFactor(int n, int k) {
        int i,j=0;
        for(i=1;i<=n;i++){
            
            if(n%i==0)
               {
                   j++;
                   if(j==k)
                    return i;
               }
            
        }
        return -1;
    }
};