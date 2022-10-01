// after partitioning an array and sorting the subsegments in ascending order, concatenate them and compare to original array
// find maximum contiguous subsegment in which the array can be partitioned

int findMaxSubsequentCount(vector<int> arr)
{
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
        }
        else
        {
            if (count > maxCount)
            {
                maxCount = count;
            }
            count = 0;
        }
    }
    return maxCount;
}
