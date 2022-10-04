class Solution {
public:
    string reverseWords(string s) {
        string S=s;
        int len = S.length();

        string res = "", tmp = "";

        stack<string> ss;

        

        for(int i=0; i<len; ++i){
            if(S[i] == ' ' && tmp=="") continue;
            if(S[i] == ' '){

                ss.push(tmp);

                tmp = "";

            }

            else

                tmp += S[i];

        }

        

        if(tmp != "")

            ss.push(tmp);

            

        while(!ss.empty()){

            res += ss.top();

            if(ss.size() > 1)

                res += ' ';

            ss.pop();

        }

        

        return res;
    }
};