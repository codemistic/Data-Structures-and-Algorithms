package com.company;

import java.util.Arrays;

class Leetcode338 {
  public static void main(String[] args) {
   int n = 5;
//   int[] arr = new int[n+1];
    int[] arr=bitsArray(n);
   System.out.println(Arrays.toString(arr));
  }


   static int[] bitsArray(int n) {
    int[] arr = new int[n+1];
    for(int i=0;i<=n;i++) {
     int num=i;
     int j=i,k=0,c=0;
     while (k <= 31) {
      if ((num & 1) == 1) {
       c++;
      }
      num = num >> 1;
      k++;
     }
     arr[j] = c;
    }
    return arr;
   }
   }