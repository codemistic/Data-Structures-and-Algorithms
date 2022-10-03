/** Leetcode - 1863. Sum of All Subset XOR Totals(https://leetcode.com/problems/sum-of-all-subset-xor-totals/)
Question:The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 
Note: Subsets with the same elements should be counted multiple times.
An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
*/

class Solution {
    int sum=0;
    
    public int subsetXORSum(int[] n) {
        if(n.length==1){
            return n[0];
        }
        else if(n.length==2){
            return (n[0]+n[1]+n[0]^n[1]);
        }
        boolean b[]=new boolean[n.length];
        Arrays.fill(b,false);
        int a=0;
        int s=0;
        s+=n[0];
        String st="";
        for(int i=1;i<n.length;i++){
            s+=n[i];
            sum=0;
            a=xor(n,0,i+1,b,0,-1,st);
            s+=a; 
        }
        return s;
    }
    public int xor(int[] n,int co, int te,boolean[] b, int s,int li, String st){
        if(co==te){
            sum+=s;
            return s;
        }
        for(int i=li+1;i<n.length;i++){
            if(b[i]==false){
                b[i]=true;
                int x=s;
                s=s^n[i];
                int a=xor(n,co+1,te,b,s,i,st+" "+n[i]);
                s=x;
                b[i]=false;
            }
        }
        return sum;
    }
}
