public class Solution {
    public long kMirror(int k, int n) {
        long ans = 0;
        int cnt = 0;
        long[] pow10 = new long[12];
        pow10[0] = 1;
        for (int i = 1; i < 12; i++) pow10[i] = pow10[i - 1] * 10;

        while (cnt < n) {
            int len = 1;
            for (; ; len++) {
                int half = (len + 1) / 2;
                long start = pow10[half - 1], end = pow10[half];
                for (long h = (half == 1 ? 1 : start); h < end && cnt < n; h++) {
                    long t = h, rev = 0, x = h;
                    if ((len & 1) == 1) t /= 10;
                    while (t > 0) {
                        rev = rev * 10 + t % 10;
                        t /= 10;
                    }
                    long p = x * pow10[len - half] + rev;
                    if (isPal(p, k)) {
                        ans += p;
                        cnt++;
                        if (cnt == n) return ans;
                    }
                }
            }
        }
        return ans;
    }

    private boolean isPal(long x, int k) {
        long t = x, rev = 0;
        while (t > 0) {
            rev = rev * k + t % k;
            t /= k;
        }
        return rev == x;
    }

    // Main function to test the solution
    public static void main(String[] args) {
        Solution sol = new Solution();

        int k1 = 2, n1 = 5;
        System.out.println("Input: k = " + k1 + ", n = " + n1);
        System.out.println("Output: " + sol.kMirror(k1, n1)); // Expected: 25

        int k2 = 3, n2 = 7;
        System.out.println("\nInput: k = " + k2 + ", n = " + n2);
        System.out.println("Output: " + sol.kMirror(k2, n2)); // Expected: 499

        int k3 = 7, n3 = 17;
        System.out.println("\nInput: k = " + k3 + ", n = " + n3);
        System.out.println("Output: " + sol.kMirror(k3, n3)); // Expected: 20379000
    }
}
