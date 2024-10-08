class Solution {
    private:
    vector<vector<int>> printPascal(int n)
    {
     vector<int> b;
    for (int line = 1; line <= n; line++)
    {
        int C = 1; 
        for (int i = 1; i <= line; i++)
        {
            b.push_back(C);
            C = C * (line - i) / i;
        }
        v.push_back(b);
        b.clear();
        
    }
        return v;
}
public:
    vector<vector<int>> v;
    vector<vector<int>> generate(int numRows) 
    {
        return printPascal(numRows);
    }
};