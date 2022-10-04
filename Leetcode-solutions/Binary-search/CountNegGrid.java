public class CountNegGrid {
    public static void main(String[] args) {

    }

    static int countNegatives(int[][] grid) {
        int s = 0;
        int e = grid[0].length-1;
        int count = 0;

        while(s < grid.length && e >= 0){
            if(grid[s][e] < 0){
                count += grid.length - s;
                e--;
            } else{
                s++;
            }
        }
        return count;
    }
}
