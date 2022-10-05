// Name : Search_a_2D_Matrix_II
// Leetcode Problem 240 (Medium)
// Url : https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int j = matrix[0].size() - 1, i = 0;
        while (1)
        {
            if (j < 0 || i > matrix.size() - 1)
                return 0;
            if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return 1;
        }
        if (matrix[i][j] == target)
            return 1;
        return 0;
    }
};
