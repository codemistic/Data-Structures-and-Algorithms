//Ankita Patil

class knapsack {
    int knap(int[] wt, int[] val, int W, int n) {
        int[][] M = new int[n + 1][W + 1];
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (w == 0 || i == 0)
                    M[i][w] = 0;
                else if (wt[i - 1] > w)
                    M[i][w] = M[i - 1][w];
                else
                    M[i][w] = Math.max(M[i - 1][w], val[i - 1] + M[i - 1][w - wt[i - 1]]);
            }
        }
        int i = n, k = W;
        while (i > 0 && k > 0) {
            if (M[i][k] != M[i - 1][k]) {
                System.out.println(i);
                i = i - 1;
                k = k - wt[i];
            } else
                i = i - 1;
        }
        return M[n][W];
    }

    public static void main(String[] args) {
        int[] val = new int[] { 10, 4, 9, 11 };
        int[] wt = new int[] { 3, 5, 6, 2 };
        int W = 7;
        int n = val.length;
        knapsack ob = new knapsack();
        System.out.println("Maximum value in Knapsack: " + ob.knap(wt, val, W, n));
    }

}