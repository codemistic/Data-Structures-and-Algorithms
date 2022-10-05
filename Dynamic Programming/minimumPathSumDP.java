/*https://leetcode.com/problems/minimum-path-sum/
 * dp easy, striver op
 *
 */

private class Recursion {

  public int minPathSum(int[][] grid) {
    int n = grid.length;
    int m = grid[0].length;
    return recursion(n - 1, m - 1, grid);
  }

  private int recursion(int i, int j, int[][] grid) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return Integer.MAX_VALUE;
    int up = recursion(i - 1, j, grid); // travelling from upside
    int left = recursion(i, j - 1, grid); // travelling from righside
    return grid[i][j] + Math.min(up, left);
  }
}

private class memoization {
  int dp[][];

  public int minPathSum(int[][] grid) {
    int n = grid.length;
    int m = grid[0].length;
    dp = new int[n][m];
    for (int a[] : dp) {
      Arrays.fill(a, -1);
    }
    return recursion(n - 1, m - 1, grid);
  }

  private int recursion(int i, int j, int[][] grid) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return Integer.MAX_VALUE;
    if (dp[i][j] != -1) return dp[i][j];
    int up = recursion(i - 1, j, grid); // travelling from upside
    int left = recursion(i, j - 1, grid); // travelling from righside
    return dp[i][j] = grid[i][j] + Math.min(up, left);
  }
}

private class tabulation {
  int dp[][];

  public int minPathSum(int[][] grid) {
    int n = grid.length;
    int m = grid[0].length;
    dp = new int[n][m];
    for (int a[] : dp) {
      Arrays.fill(a, -1);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) dp[i][j] = grid[i][j];
        if (dp[i][j] != -1) continue; else if (i == 0 && j != 0) dp[i][j] =
          grid[i][j] + dp[i][j - 1]; else if (i != 0 && j == 0) dp[i][j] =
          grid[i][j] + dp[i - 1][j]; else {
          dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n - 1][m - 1];
  }
}
