class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // nrows---> Number of rows, mcols---> Number of columns
        int nrows = matrix.size();
        int mcols = matrix[0].size(); // Because, No. of columns = length of any particular row

        int start = 0;
        int end = nrows * mcols - 1;
        int mid = (start + end) / 2; // Finding mid index

        while (start <= end)
        {
            mid = (start + end) / 2;

            int element = matrix[mid / mcols][mid % mcols]; // Finding the element at mid index

            if (element == target)
            {
                return true;
            }
            else if (element < target)
            {
                start = mid + 1;
            }
            else //(element > target)
            {
                end = mid - 1;
            }
        }
        return 0;
    }
};