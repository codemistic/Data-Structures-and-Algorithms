class Spiral_Matrix {
    public static void main(String[] args){
        int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
        Spiral_Matrix ob = new Spiral_Matrix();
        System.out.println(ob.spiralOrder(matrix));
    }
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[][] visited = new boolean[matrix.length][matrix[0].length];
        int count = 0;
        int row = 0;
        int col = 0;
        boolean right = true;
        boolean left = false;
        boolean down = false;
        boolean up = false;
        boolean curr = right;
        while(count!=(matrix.length*matrix[0].length)){
            if(!valid(row,col,matrix)){
                if(curr==right){
                    col--;
                    row++;
                    down = true;
                    right = false;
                    curr = down;
                }
                else if(curr==left){
                    col++;
                    row--;
                    left = false;
                    up = true;
                    curr = up;
                }
                else if(curr==down){
                    col--;
                    row--;
                    down = false;
                    left = true;
                    curr = left;
                }
                else if(curr==up){
                    col++;
                    row--;
                    up = false;
                    right = true;
                    curr = right;
                }
            }
            if(!visited(row,col,visited)){
                visited[row][col] = true;
                ans.add(matrix[row][col]);
                count++;
                if(right){
                    col++;
                }
                else if(left){
                    col--;
                }
                else if(down){
                    row++;
                }
                else if(up){
                    row--;
                } 
            }
            else{
                if(curr==right){
                    col--;
                    row++;
                    down = true;
                    right = false;
                    curr = down;
                }
                else if(curr==left){
                    col++;
                    row--;
                    left = false;
                    up = true;
                    curr = up;
                }
                else if(curr==down){
                    col--;
                    row--;
                    down = false;
                    left = true;
                    curr = left;
                }
                else if(curr==up){
                    col++;
                    row++;
                    up = false;
                    right = true;
                    curr = right;
                }
            }

        }
        return ans;
    }
    private boolean valid(int r, int c, int[][] matrix){
        boolean row = (r>=0)&&(r<matrix.length);
        boolean col = (c>=0)&&(c<matrix[0].length);
        return row&&col;
    }
    private boolean visited(int r, int c, boolean[][] mat){
        return mat[r][c];
    }
}
