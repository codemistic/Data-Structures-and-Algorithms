// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0; 

        for (int row = 0; row < grid.size(); row++) {
            for (int col = grid[row].size()-1; col >= 0; col--) {
                if (grid[row][col] < 0) 
                    count++; 
                else 
                    break; 
            }
        }
        return count; 
    }
};