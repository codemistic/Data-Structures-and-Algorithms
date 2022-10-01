/*
   LEETCODE QUESTION : 1812. Determine Color of a Chessboard Square

 */

public class Determine_Color_of_a_Chessboard_Square {

    public boolean squareIsWhite(String coordinates) {

        int a = coordinates.charAt(0);
        int b = coordinates.charAt(1);
        if ((a + b) % 2 == 0) {
            return false;
        } else
            return true;

    }

}
