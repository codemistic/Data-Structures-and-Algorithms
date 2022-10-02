package PatternQuestions;

public class Question3 {
    public static void main(String[] args) {
          pattern3(5);
    }
    static void pattern3(int n) {
        for(int row=n;row>=1;row--) {
            for(int j=1;j<=row;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
