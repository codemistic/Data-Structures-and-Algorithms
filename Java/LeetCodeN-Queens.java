/* Question Link: https://leetcode.com/problems/n-queens/
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 */






class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> results = new ArrayList<>();
        if(n ==0) return results;
        backtrace(results, new ArrayList<String>(), 0, n, new boolean[n]);
        return results;
    }
    
     public static void backtrace(List<List<String>> result, List<String> list, int level, int n, boolean[] used){
        if(level == n) result.add(new ArrayList<String>(list));
        else{
            for(int i = 0; i < n; i++){
                if(used[i]) continue;
                if(isValid(list, level, i, n)){
                    list.add(createQueen(n, i));
                    used[i] = true;
                    backtrace(result, list, level + 1, n, used);
                    used[i] = false;
                    list.remove(list.size() - 1);
                }
            }
        }
    }
    public static boolean isValid(List<String> list, int row, int column, int n){
        if(row > 0){
            String cmp = list.get(row - 1);
            for(int i = 0; i < row; i++)
                if(list.get(i).charAt(column) == 'Q') return false;
            int tempRow = row;
            int tempCol = column;
            while(--tempRow >= 0 && --tempCol >= 0){
                if(list.get(tempRow).charAt(tempCol) == 'Q') return false;
            }
            tempRow = row;
            tempCol = column;
            while(--tempRow >= 0 && ++tempCol <= n-1)
                if(list.get(tempRow).charAt(tempCol) == 'Q') return false;
        }
        return true;
    }
    private static String createQueen(int n, int index){
        StringBuilder sb = new StringBuilder();
        int i = 0;
        for(; i < index; i++)
            sb.append('.');
        sb.append('Q');
        for(++i; i < n; i++){
            sb.append('.');
        }
        return sb.toString();
    }
    
    
}

/*contributed by: nilesh05apr */