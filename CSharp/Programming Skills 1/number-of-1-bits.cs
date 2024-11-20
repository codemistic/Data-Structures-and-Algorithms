public class Solution {
    public int HammingWeight(uint n) {
        int count = 0;
        while (count < n) {
            n &= n - 1;
            count++;
        }
        return count;
    }
}