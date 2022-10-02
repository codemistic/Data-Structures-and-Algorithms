package PatternQuestions;

public class Question5 {
    public static void main(String[] args) {
        int n=5;
        for(int row=1;row<=n;row++) {
            for(int col=1;col<=row;col++){
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int row=n-1;row>=1;row--) {
            for(int j=1;j<=row;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
