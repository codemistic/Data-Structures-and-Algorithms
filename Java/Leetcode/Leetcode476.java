package com.company;

public class Leetcode476 {
    public static void main(String[] args) {
        int n = 5;
        int ans = compliment(n);
        System.out.println(ans);
    }

    static int compliment(int n) {
        return ~n;
    }
}