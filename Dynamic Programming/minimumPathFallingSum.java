/*https://leetcode.com/problems/minimum-falling-path-sum/submissions/
 *
 */
// minimum hai bhai
private class recursion {

  public int minFallingPathSum(int[][] matrix) {
    int n = matrix.length;
    int m = matrix[0].length;

    int ans = Integer.MAX_VALUE;

    for (int j = 0; j < m; j++) {
      ans = Math.min(ans, recur(n - 1, j, matrix));
    }
    return ans;
  }

  private int recur(int i, int j, int[][] matrix) {
    // out of bound errors
    if (j < 0 || j >= matrix[0].length) return Integer.MAX_VALUE;
    // if reawched the first row, then only
    if (i == 0) return matrix[0][j];

    int up = recur(i - 1, j, matrix);
    int leftdiagonal = recur(i - 1, j - 1, matrix);
    int rightdiagonal = recur(i - 1, j + 1, matrix);
    return matrix[i][j] + Math.min(up, Math.min(leftdiagonal, rightdiagonal));
  }
}

private class memoisation {
  int dp[][];

  public int minFallingPathSum(int[][] matrix) {
    int n = matrix.length;
    int m = matrix[0].length;
    dp = new int[n][m];
    int ans = Integer.MAX_VALUE;
    // fill dp with min value
    for (int a[] : dp) {
      Arrays.fill(a, Integer.MAX_VALUE);
    }

    for (int j = 0; j < m; j++) {
      ans = Math.min(ans, recur(n - 1, j, matrix));
    }
    return ans;
  }

  private int recur(int i, int j, int[][] matrix) {
    // out of bound errors
    if (j < 0 || j >= matrix[0].length) return Integer.MAX_VALUE;
    // if reawched the first row, then only
    if (i == 0) return matrix[0][j];
    if (dp[i][j] != Integer.MAX_VALUE) return dp[i][j];

    int up = recur(i - 1, j, matrix);
    int leftdiagonal = recur(i - 1, j - 1, matrix);
    int rightdiagonal = recur(i - 1, j + 1, matrix);
    return (
      dp[i][j] =
        matrix[i][j] + Math.min(up, Math.min(leftdiagonal, rightdiagonal))
    );
  }
}

private class tabulation {
  int dp[][];

  public int minFallingPathSum(int[][] matrix) {
    int n = matrix.length;
    int m = matrix[0].length;
    dp = new int[n][m];
    int ans = Integer.MAX_VALUE;
    // fill dp with min value
    for (int a[] : dp) {
      Arrays.fill(a, Integer.MAX_VALUE);
    }

    // filling the first array
    for (int i = 0; i < m; i++) {
      dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++) {
      for (int col = 0; col < m; col++) {
        // check out of boound and go
        dp[i][col] = matrix[i][col];

        int up = dp[i - 1][col];
        int leftdiag = dp[i - 1][Math.max(0, col - 1)];
        int rightdiag = dp[i - 1][Math.min(m - 1, col + 1)];

        // minimum from the rest of moves
        dp[i][col] += Math.min(up, Math.min(leftdiag, rightdiag));
      }
    }

    // return the minimum value from the end
    for (int j = 0; j < m; j++) {
      ans = Math.min(ans, dp[n - 1][j]);
    }
    return ans;
  }

  private int recur(int i, int j, int[][] matrix) {
    // out of bound errors
    if (j < 0 || j >= matrix[0].length) return Integer.MAX_VALUE;
    // if reawched the first row, then only
    if (i == 0) return matrix[0][j];
    if (dp[i][j] != Integer.MAX_VALUE) return dp[i][j];

    int up = recur(i - 1, j, matrix);
    int leftdiagonal = recur(i - 1, j - 1, matrix);
    int rightdiagonal = recur(i - 1, j + 1, matrix);
    return (
      dp[i][j] =
        matrix[i][j] + Math.min(up, Math.min(leftdiagonal, rightdiagonal))
    );
  }
}
