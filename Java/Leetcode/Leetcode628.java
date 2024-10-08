package com.company;

public class Leetcode628 {
    public static void main(String[] args) {
        int[] arr={-1,-2,-3};
        int ans=product(arr);
        System.out.println(ans);
    }

    static int product(int[] arr){
        int i=0,prod=1;
        while(i<arr.length){
            int correctIndex=arr[i]-1;
            if(arr[i]!=arr[correctIndex]){
                swap(arr,i,correctIndex);
            }
            else {
                i++;
            }
        }

        for(int j=arr.length-1;j>arr.length-4;j--){
            prod=arr[j]*prod;
        }
        return prod;
    }


    static void swap(int[] arr, int a, int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

}