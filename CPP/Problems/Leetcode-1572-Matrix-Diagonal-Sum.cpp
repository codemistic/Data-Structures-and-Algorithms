// https://leetcode.com/problems/matrix-diagonal-sum/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rc = 0; 
        int TotalSum = 0; 
        // Primary Diagonal
        while (rc < mat.size()) {
            TotalSum += mat[rc][rc];
            rc++; 
        }
        // Secondary Diagonal
        int r = mat.size()-1, c = 0; 
        while (r >= 0 && c < mat.size()) {
            TotalSum += mat[r][c];
            r--; 
            c++;    
        }
        if (mat.size() & 1) 
            return TotalSum - (mat[mat.size()/2][mat.size()/2]);
        return TotalSum; 
    }
};