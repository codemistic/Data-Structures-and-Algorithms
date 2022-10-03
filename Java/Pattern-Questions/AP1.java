package PatternQuestions;

public class AP1 {
    public static void main(String[] args) {
        Q1(4,5);

    }
    static void Q1(int m,int n) {
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++) {
                if(i==1||i==m||j==1||j==n){
                    System.out.print("*");
                }
                else System.out.print(" ");
            }
            System.out.println();
        }
    }
}
