package PatternQuestions;

public class Question6 {
    public static void main(String[] args) {
        int n=5;
        for(int row=1;row<=n;row++){
            for(int i=1;i<=n-row;i++){
                System.out.print(" ");
            }
            for(int j=1;j<=row;j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
