package PatternQuestions;

public class Question8 {
    public static void main(String[] args) {
        int n=5; // --> simply see the no. of rows and declare that value to n.

        for(int row=1;row<=n;row++){
            for(int spaces=1;spaces<=n-row;spaces++){
                System.out.print(" ");
            }
            for(int j=1;j<=(2*row-1);j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
