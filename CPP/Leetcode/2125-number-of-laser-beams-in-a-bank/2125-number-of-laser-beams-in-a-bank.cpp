class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int f=0;
        vector<int> v;
        int cnt=0;
        for(int i=0;i<bank.size();i++)
        {
            for(int j=0;j<bank[i].length();j++)
            {
                if(bank[i][j]=='1') cnt++;
            }
            if(cnt!=0) v.push_back(cnt);
            cnt=0;
        }
        if(v.size()==1 || v.size()==0)
        {
            return 0;
        }
        int sum=0;
        
        for(int i=0;i<v.size()-1;i++)
        {
            sum=sum+(v[i]*v[i+1]);
        }
        return sum;
    }
};