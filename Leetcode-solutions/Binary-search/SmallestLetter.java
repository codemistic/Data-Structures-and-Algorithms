//question = https://leetcode.com/problems/find-smallest-letter-greater-than-target/

public class SmallestLetter {
    public static void main(String[] args) {
        char[] letters = {'c', 'f', 'j'};
        char target = 'c';
        System.out.println(nextGreatestLetter2(letters, target));
    }

    static char nextGreatestLetter(char[] letters, char target) {
        int s = 0;
        int e = letters.length-1;

        while(s <= e){
            int m = s + (e-s)/2;

            if(target < letters[m]){
                e = m-1;
            } else {
                s = m+1;
            }
        }
        return letters[ s % letters.length ];  //or put a condition above like if target > letters[letters.length-1] then return 0 and here just return s
    }

    static char nextGreatestLetter2(char[] letters, char target){
        if(target >= letters[letters.length-1]){
            return letters[0];
        }

        int s = 0;
        int e = letters.length-1;

        while(s < e){
            int m = s + (e-s)/2;

            if(target < letters[m]){
                e = m-1;
            } else{
                s = m+1;
            }
        }
        return letters[s] > target ? letters[s] : letters[s+1];
    }



}
