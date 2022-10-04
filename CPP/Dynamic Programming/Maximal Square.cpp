// https://leetcode.com/problems/maximal-square/
// Maximal Square

class Solution {
public:
    
    
    int solveTab(vector<vector<char>>& matrix, int &maxi)
    {
        vector<int>prev(matrix[0].size() + 1, 0);
        vector<int>curr(matrix[0].size() + 1);
        
        for (int row = matrix.size() - 1; row >= 0; row --)
        {
            for (int column = matrix[0].size() - 1; column >= 0; column--)
            {
                int right = curr[column + 1];
                int diag = prev[column + 1];
                int down = prev[column];
        
                if (matrix[row][column] == '1')
                {
                    int ans = 1 + min(right, min(diag, down));
                    maxi = max(maxi , ans);
                    curr[column] = ans;
                 
                }
                else
                {
                    curr[column] = 0;
                }
            }
            prev = curr;
        }   
        return 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int maxi = 0;
        solveTab(matrix, maxi);
        return maxi * maxi;
    }
};