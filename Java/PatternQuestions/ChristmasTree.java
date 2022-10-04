package PatternQuestions;

public class ChristmasTree {
    public static void main(String[] args) {
        int n=5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            for(int k=1;k<=i;k++){
                System.out.print("*"+" ");

            }
            System.out.println();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            for(int k=1;k<=i+2;k++){
                System.out.print("*"+" ");
            }
            System.out.println();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            for(int k=1;k<=i+4;k++){
                System.out.print("*"+" ");
            }
            System.out.println();
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            for(int k=1;k<=i+6;k++){
                System.out.print("*"+" ");
            }
            System.out.println();
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            for(int k=1;k<=i+8;k++){
                System.out.print("*"+" ");
            }
            System.out.println();
        }
        int m=4;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                System.out.print("*"+" ");
            }
            System.out.println();
        }
    }
}
