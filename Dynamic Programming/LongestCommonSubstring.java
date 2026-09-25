/**
 * Problem: Longest Common Substring
 *
 * Given two strings s1 and s2, find the length of the longest common substring.
 * A substring is a contiguous sequence of characters.
 *
 * Example:
 * Input:
 * s1 = "abcdxyz"
 * s2 = "xyzabcd"
 *
 * Output:
 * 4
 *
 * Explanation:
 * The longest common substrings are "abcd" and "xyz".
 *
 * ----------------------------------------------------
 * Approach: Dynamic Programming
 *
 * Let dp[i][j] represent the length of the longest common substring
 * ending at index (i - 1) in s1 and (j - 1) in s2.
 *
 * If s1[i - 1] == s2[j - 1]:
 *      dp[i][j] = dp[i - 1][j - 1] + 1
 * Else:
 *      dp[i][j] = 0
 *
 * We keep track of the maximum value in the DP table.
 *
 * ----------------------------------------------------
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 */

public class LongestCommonSubstring {

    /**
     * Returns the length of the longest common substring
     * between two given strings.
     */
    public static int longestCommonSubstring(String s1, String s2) {

        int n = s1.length();
        int m = s2.length();

        // DP table where dp[i][j] stores length of
        // longest common substring ending at s1[i-1] and s2[j-1]
        int[][] dp = new int[n + 1][m + 1];

        int maxLength = 0;

        // Build the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // If characters match, extend the substring
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = Math.max(maxLength, dp[i][j]);
                } else {
                    // Reset to 0 when characters do not match
                    dp[i][j] = 0;
                }
            }
        }

        return maxLength;
    }

    // Driver code for quick testing
    public static void main(String[] args) {
        String s1 = "abcdxyz";
        String s2 = "xyzabcd";

        System.out.println("Length of Longest Common Substring: "
                + longestCommonSubstring(s1, s2));
    }
}
