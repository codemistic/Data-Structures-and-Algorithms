// Name : Search_a_2D_Matrix_II
// Leetcode Problem 240 (Medium)
// Url : https://leetcode.com/problems/search-a-2d-matrix-ii/

// Approach 1 (Best Approach)
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

// Approach 2

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix[0].size();i++)
            {
            if(matrix[0][i]>target)
                return 0;
            int low=0,high=matrix.size()-1;
            while(low<high){
                int mid=low+(high-low+1)/2;
                    if(matrix[mid][i]<=target)
                        low=mid;
            else
                high=mid-1;
            }
            if(matrix[low][i]==target)
                return 1;
        }
        return 0;
    }
};
