package com.company;

import java.util.Arrays;

public class Leetcode287 {
    public static void main(String[] args) {
        int[] arr={3,1,3,4,2};
        sort(arr);
        System.out.println(arr[arr.length-1]);

    }

    static void sort(int[] arr){
        int i=0;
        while(i<arr.length){
            int correctIndex=arr[i]-1;
            if(arr[i]!=arr[correctIndex]){
                swap(arr,i,correctIndex);
            }
            else {
                i++;
            }
        }
    }


    static void swap(int[] arr, int a, int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    }