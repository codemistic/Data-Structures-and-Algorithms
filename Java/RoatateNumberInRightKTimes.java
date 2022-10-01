package XtraQuestions.StringsArrayMixed;
// You are given two numbers n and k. You are required to rotate n k times to the right. If kis positive, rotate to the right l.e. remove rightmost digit and make it leftmost. Do the reverse for negative value of k. Also k can have an absolute value larger than number of digits in n. 2. Take as input n and k. 3. Print the rotated number. 4. 
// Note - Assume that the number of rotations will not cause leading O's in the result, e.g. such an input will not be given
// n = 12340056 k= 3 r = 05612340
// Constraints 1 <= n < 10^9 - 10^9 < k < 10^9
// Format
// Input
// "n" where n is any integer. "K" where k is any integer.
// Output
// "r", the rotated number
// SAMPLE INPUT
// 562984
// 2
// OUTPUT
// 845629

import java.util.*;

public class RoatateNumberInRightKTimes {
    public static void main(String[] args) {
        // int n = 12340056; // This type of number is not allowed
        int n = 124452;
        System.out.println(n);
        
        int k = 2;
        
        int frontnum = 0;
        for(int i=0; i<k; i++){
            int rem = n%10;
            int remaining = n/10;
            
            // for 0's in between we have to use this
            // if(rem==0){
            //     String padded = String.format("%08d" , remaining);
            //     // System.out.println("padded: "+ padded);
            //     n = Integer.parseInt(padded);
            //     // n = padded;
            //     System.out.println("the n is : " + n);
            //     continue;
            // }
            int count = 0;
            int temp = remaining;
            while(temp!=0){
                count++;
                temp = temp/10;
            }
            // System.out.println("count : " + count);
            frontnum = rem*(int)(Math.pow(10,count)) + remaining;
            n = frontnum;
            // System.out.println("frontnum : " + frontnum);
        }

        System.out.println("The number after " + k + " rotations: " + frontnum);
    }
}
