/** Leetcode - 1137- N-th Tribonacci Number (https://leetcode.com/problems/n-th-tribonacci-number/)
Question:The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
*/

class Solution {
    public int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
            return 1;
        }
        else if(n==3){
            return 2;
        }
        else{
            int n0=0;
            int n1=1;
            int n2=1;
            int nend=0;
            for(int i=2;i<n;i++){
                nend=n0+n1+n2;
                n0=n1;
                n1=n2;
                n2=nend;
            }
            return nend;
        }
    }
    
}
//Contribution by shubhrastogi07
