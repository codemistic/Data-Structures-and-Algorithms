package PatternQuestions;

public class Question13 {
    public static void main(String[] args) {
        int n=5;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            if(i==1 || i==n) {
                for(int k=1;k<=2*i-1;k++) {
                    System.out.print("*");
                }
            }
            else{
                for(int j=1;j<=2*i-1;j++){
                    if(j==1||j==2*i-1){
                        System.out.print("*");
                    }
                    else{
                        System.out.print(" ");
                    }
                }

            }
            System.out.println();
        }
    }
}
