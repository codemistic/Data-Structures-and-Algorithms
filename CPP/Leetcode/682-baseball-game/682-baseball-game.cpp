class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        
        for(int i=0;i<ops.size();i++)
        {
            string s=ops[i];
            char c=s[0];
            int f=0;
            if(c!='D' && c!='C' && c!='+')
            {
                int k=stoi(s);
                v.push_back(k);
            }
            if(c=='C')
            {
                v.pop_back();
            }
            if(c=='D')
            {
                int k=v[v.size()-1]*2;
                v.push_back(k);
            }
            if(c=='+')
            {
                int k=v[v.size()-1]+v[v.size()-2];
                v.push_back(k);
            }
        }
        int sum=0;
        for(auto it:v)
        {
            sum+=it;
        }
        return sum;
    }
};