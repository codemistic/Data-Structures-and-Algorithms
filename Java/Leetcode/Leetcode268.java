package com.company;

public class Leetcode268 {
    public static void main(String[] args) {
        int[] arr={9,6,4,2,3,5,7,0,1};
        int ans=missing(arr);
        System.out.println(ans);;
    }


    static int missing(int[] arr){
        sort(arr);

        for(int i=0;i<arr.length;i++){
            if(arr[i]!=i){
                return i;
            }
        }
        return arr.length;
    }



    static void sort(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int charIndex = arr[i];
            if (arr[i] > arr.length-1) {
                i++;
                continue;
            }

            if (arr[i] != arr[charIndex]) {
                swap(arr, i, charIndex);
            } else {
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
