package com.company;

public class Leetcode1486 {
    public static void main(String[] args) {
        int n=4,start=3;
        int ans=xorOperation(n,start);
        System.out.println(ans);
    }

    static int xorOperation(int n,int start){
        int xor=0;
        int[] arr=new int[n];
        for(int i=0;i<=n-1;i++){
            arr[i]=start+2*i;
            xor=xor^arr[i];
        }
        return xor;
    }
}
