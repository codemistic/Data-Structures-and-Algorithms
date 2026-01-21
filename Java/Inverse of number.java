/*
Take the following as input.
A number
Assume that for a number of n digits, the value of each digit is from 1 to n and is unique. E.g. 32145 is a valid input number.

Write a function that returns its inverse, where inverse is defined as follows

Inverse of 32145 is 12543. In 32145, “5” is at 1st place, therefore in 12543, “1” is at 5th place; in 32145, “4” is at 2nd place, therefore in 12543, “2” is at 4th place.

Print the value returned.

Input Format
Integer

Constraints
0 < N < 1000000000

Output Format
Integer

Sample Input
32145
Sample Output
12543
Explanation
Assume that for a number of n digits, the value of each digit is from 1 to n and is unique. E.g. 32145 is a valid input number. 
Inverse of 32145 is 12543. In 32145, “5” is at 1st place, therefore in 12543, “1” is at 5th place; in 32145, “4” is at 2nd place, 
therefore in 12543, “2” is at 4th place.
*/

import java.util.*;
public class Main {
    public static void main(String args[]) {

        Scanner scn = new Scanner(System.in);
		int num = scn.nextInt();
        int position=0, ans=0;
    

        while(num>0){

            
            position++;
            int digit = num%10;
            num=num/10;
             
            double mult = Math.pow(10,digit-1);
            int i = (int)Math.round(mult);
            ans = (int)Math.round(ans + position*mult);
            

        }

        System.out.println(ans);


    }
}

