package com.company;

import java.util.Arrays;

public class Leetcode136 {
    public static void main(String[] args) {
        int[] arr={4,1,2,1,2};
        int ans=uniqueNumber(arr);
        System.out.println(ans);
    }

    static int uniqueNumber(int[] arr){
        int answer=0;

        for(int i=0;i<=arr.length-1;i++){
            answer^=arr[i];
        }
        return answer;
    }
}
