package com.company;

import java.util.ArrayList;
import java.util.List;

public class Leetcode645 {
    public static void main(String[] args) {
        int[] arr={1,2,2,4};
        int[] ans=disappear(arr);
        System.out.println("Repeated:"+ans[0]);
        System.out.println("Missing:"+ans[1]);

    }

    static int[] disappear(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int correctIndex = arr[i] - 1;
            if (arr[i] != arr[correctIndex]) {
                swap(arr, i, correctIndex);
            } else {
                i++;
            }
        }

        int[] ans = new int[2];
        for (int j = 0; j < arr.length; j++) {
            if (arr[j] != j + 1){
                ans[0]=arr[j];
                ans[1]=j+1;
            }
        }
        return ans;
    }

    static void swap(int[] arr, int a, int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
}
