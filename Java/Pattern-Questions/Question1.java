package PatternQuestions;

public class Question1 {
    public static void main(String[] args) {

        pattern2(5);
    }
    static void pattern2(int n) {
        for(int row=1;row<=n;row++) {
            for(int j=1;j<=n;j++){
                System.out.print("* ");
            }
            System.out.println();
        }


    }
}
