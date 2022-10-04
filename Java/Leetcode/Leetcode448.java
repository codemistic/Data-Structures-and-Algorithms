package com.company;

import java.util.ArrayList;
import java.util.List;

public class Leetcode448 {
    public static void main(String[] args) {
        int[] arr={4,3,2,7,8,2,3,1};
//    List<Integer> ans=new ArrayList<>();
        List<Integer> ans=disappear(arr);
        System.out.println(ans);
    }

    static List<Integer> disappear(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int correctIndex = arr[i] - 1;
            if (arr[i] != arr[correctIndex]) {
                swap(arr, i, correctIndex);
            } else {
                i++;
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int j = 0; j < arr.length; j++) {
            if (arr[j] != j + 1)
            { ans.add(j+1);
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