/*https://leetcode.com/problems/triangle/
 * triangle
 * strivers dp series
 */
private class recursion {

  public int minimumTotal(List<List<Integer>> tri) {
    return recur(tri, 0, 0);
  }

  private static int recur(List<List<Integer>> tri, int i, int j) {
    if (i == tri.size() - 1) {
      return tri.get(i).get(j);
    }
    int ans = tri.get(i).get(j);
    int down = recur(tri, i + 1, j); //tri.get(i+1).get(j);
    int diagonal = recur(tri, i + 1, j + 1); //tri.get(i+1).get(j+1);
    return ans + Math.min(down, diagonal);
  }
}

private class memoization {
  int dp[][];

  public int minimumTotal(List<List<Integer>> tri) {
    dp = new int[tri.size()][tri.size()];
    for (int a[] : dp) {
      Arrays.fill(a, -1);
    }
    return recur(tri, 0, 0);
  }

  private int recur(List<List<Integer>> tri, int i, int j) {
    if (i == tri.size() - 1) {
      return tri.get(i).get(j);
    }
    if (dp[i][j] != -1) return dp[i][j];
    int ans = tri.get(i).get(j);
    int down = recur(tri, i + 1, j); //tri.get(i+1).get(j);
    int diagonal = recur(tri, i + 1, j + 1); //tri.get(i+1).get(j+1);
    return dp[i][j] = ans + Math.min(down, diagonal);
  }
}
