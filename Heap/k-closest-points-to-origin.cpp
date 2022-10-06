class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); i++)
        {
            int d_sqr = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push(make_pair(d_sqr, i));
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (maxHeap.size() > 0)
        {
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return ans;
    }
};