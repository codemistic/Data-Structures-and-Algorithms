class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>ml(n,-1),mr(n,-1);
        for(int i=n-2;i>=0;i--)
        {
            int x=max(mr[i+1],height[i+1]);
            if(x>height[i])
                mr[i]=x;
        }
        for(int i=1;i<n;i++)
        {
            int x=max(ml[i-1],height[i-1]);
            if(x>height[i])
                ml[i]=x;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(ml[i]!=-1&&mr[i]!=-1)
            {
                ans+=abs(min(ml[i],mr[i])-height[i]);  
            }
        }
        return ans;
    }
};

