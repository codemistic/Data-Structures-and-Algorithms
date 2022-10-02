package PatternQuestions;

public class Question2 {
    public static void main(String[] args) {

        int n=4;

        pattern2(n);
    }
    static void pattern2(int n) {
        for(int row=1;row<=n;row++) {
            for(int col=1;col<=row;col++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
