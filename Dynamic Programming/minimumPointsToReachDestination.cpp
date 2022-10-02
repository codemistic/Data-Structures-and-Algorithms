/* Given a grid of size M*N with each cell consisting of an integer which represents points. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :

1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

Example 1:

Input: M = 3, N = 3
       arr[][] = {{-2,-3,3},
                  {-5,-10,1},
                  {10,30,-5}};

Output: 7
Explanation: 7 is the minimum value to
reach the destination with positive
throughout the path. Below is the path.
(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)
We start from (0, 0) with 7, we reach
(0, 1) with 5, (0, 2) with 2, (1, 2)
with 5, (2, 2) with and finally we have
1 point (we needed greater than 0 points
at the end).
Example 2:
Input: M = 3, N = 2
       arr[][] = {{2,3},
                  {5,10},
                  {10,30}};
Output: 1
Explanation: Take any path, all of them
are positive. So, required one point
at the start */

// https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    // memoization
    // 	int f(int x,int y,vector<vector<int>>& points,vector<vector<int>>& dp) {
    // 	    int n = points.size(), m = points[0].size();

    // 	    if(x == n-1 and y == m-1){
    // 	        if(points[x][y] < 0 ) return 1-points[x][y];
    // 	        return 1;
    // 	    }
    // 	    if(dp[x][y] != -1) return dp[x][y];

    // 	    int down = ( x < n-1 ) ? f(x+1,y,points,dp) : INT_MAX;
    // 	    int right = ( y < m-1 ) ? f(x,y+1,points,dp) : INT_MAX;
    // 	    int ans = min(down,right);

    // 	    return max(ans-points[x][y],1);
    // 	}

    int minPoints(vector<vector<int>> points, int p, int q)
    {
        // Your code goes here
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(0,0,points,dp);

        //Tabulation
        int n = points.size(), m = points[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof dp);
        dp[n - 1][m - 1] = points[n - 1][m - 1] < 0 ? 1 - points[n - 1][m - 1] : 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 and j == m - 1)
                    continue;
                int down = (i < n - 1) ? dp[i + 1][j] : INT_MAX;
                int right = (j < m - 1) ? dp[i][j + 1] : INT_MAX;
                int ans = min(down, right);

                dp[i][j] = max(ans - points[i][j], 1);
            }
        }

        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        Solution ob;
        cout << ob.minPoints(a, m, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends