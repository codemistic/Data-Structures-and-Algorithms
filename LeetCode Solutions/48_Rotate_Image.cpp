class Solution
{
public:
    void rotate(vector<vector<int>> &mt)
    {
        int n = mt.size();
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = tmp; j < n; j++)
            {
                swap(mt[i][j], mt[j][i]);
            }
            tmp++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (n / 2); j++)
            {
                swap(mt[i][j], mt[i][n - j - 1]);
            }
        }
    }
};