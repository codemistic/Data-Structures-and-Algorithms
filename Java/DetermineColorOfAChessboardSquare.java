/*
   LEETCODE QUESTION : 1812. Determine Color of a Chessboard Square

 */

public class DetermineColorOfAChessboardSquare {

    public boolean squareIsWhite(String coordinates) {

        int a = coordinates.charAt(0);
        int b = coordinates.charAt(1);
        if ((a + b) % 2 == 0) {
            return false;
        } else
            return true;

    }

}
