package com.company;

 public class Leetcode191 {
     public static void main(String[] args) {
         int n = 429;
         int answer = setBits(n);
         System.out.println(answer);
     }

     static int setBits(int n) {
         int c = 0, i = 0;
         while (i <= 31) {
             if ((n & 1) != 0) {
                 c++;
             }
             n = n >> 1;
             i++;
         }
         return c;
     }
 }