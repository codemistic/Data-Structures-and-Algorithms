package com.company;

public class Leetcode190 {
    public static void main(String[] args) {
        int n = 25;
        int answer = reverseBits(n);
        System.out.println(answer);
    }

    static int reverseBit(int n) {
        int rev = 0;
        for (int i = 0; i <= 31; i++) {
            rev = rev << 1;
            rev = rev + (n & 1);
            n = n >> 1;
        }
        return rev;
    }

    static int reverseBits(int n) {
        int res=0;
        for(int i=0;i<32;i++)  //length of word is 32
        {
            res=res<<1;        //this is like multiplying the number with 10 in decimal here we left shift it as in multiplying by 2
            res+=(n&1);     //add number after taking it's & with 1
            n=n>>1;          //divide number by 2 to get next digit
        }
        return res;
    }
}
