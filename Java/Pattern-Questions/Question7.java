package PatternQuestions;

public class Question7 {
    public static void main(String[] args) {
        int n=5;
        for(int row=n;row>=1;row--){
            for(int i=1;i<=n-row;i++){
                System.out.print(" ");
            }
            for(int j=1;j<=row;j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
