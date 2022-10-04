class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string s[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s1;
        for(int i=0;i<words.size();i++)
        {
            string k="";
            for(int j=0;j<words[i].size();j++)
            {
                 k=k+s[words[i][j]-'a'];
            }
            s1.insert(k);
            k="";
        }
        return s1.size();
    }
};