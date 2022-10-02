class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector <string> result;
        letterPermute(s,result,0);
        return result;
    }
    
    void letterPermute(string s, vector<string>& result, int k)
    {
        result.push_back(s);
  
        for(int i=k;i<s.size();i++)
        {
            cout<<i<<endl;
            if(!isalpha(s[i]))
                continue;
            else
            {
                if(islower(s[i]))
                {
                    s[i] = toupper(s[i]);
                    letterPermute(s,result, i+1);
                    s[i] = tolower(s[i]);
                }
                else
                {
                    s[i] = tolower(s[i]);
                    letterPermute(s,result,i+1);
                    s[i] = toupper(s[i]);
                }
            }
        }
        return;
    }
};