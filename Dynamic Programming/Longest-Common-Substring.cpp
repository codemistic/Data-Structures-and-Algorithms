/* Dynamic Programming solution to find length of the longest common substring*/ 
#include <bits/stdc++.h>

using namespace std;

int LongestCommonSubStr(string X, string Y, int m, int n) {

  int dp[m + 1][n + 1];
  int result = 0;

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;

      else if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        result = max(result, dp[i][j]);
      } else
        dp[i][j] = 0;
    }
  }
  return result;
}

int main() {
  string X = "FirstCommit";
  string Y = "LastCommit";

  int m = X.length();
  int n = Y.length();

  cout << "Length of Longest Common Substring is " << LongestCommonSubStr(X, Y, m, n);
  return 0;
}