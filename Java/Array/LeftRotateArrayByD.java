package com.company;

public class LeftRotateArrayByD {

    //Reversal Algorithm-->
    static void reverse(int[] arr, int low, int high){
        int temp=0;
        while (low<high) {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }

    static void leftRotate(int[] arr, int d){
        if (d==0)
            return;

        int n=arr.length;
        reverse(arr,0,d-1);
        reverse(arr, d,n-1);
        reverse(arr,0,n-1);
    }

    // Better Method-->

//    static void leftRotate(int[] arr, int d){
//        int[] temp = new int[d];
//        for (int i=0; i<d; i++)
//            temp[i]=arr[i];
//        for (int i=d; i< arr.length; i++)
//            arr[i-d]=arr[i];
//        for (int i=0; i<d; i++)
//            arr[arr.length-d+1]=temp[i];
//    }

    // Naive Method-->

//    static void leftRotateOne(int[] arr){
//        int n = arr.length;
//        int temp = arr[0];
//        for (int i=1; i<arr.length; i++)
//            arr[i-1]=arr[i];
//        arr[n-1]=temp;
//    }
//    static void LeftRotate(int[] arr, int d){
//        for (int i=0; i<d; i++)
//            leftRotateOne(arr);
//    }
    public static void main(String[] args) {
        int[] arr = new int[]{1,2,3,4,5};
        int d = 2;
        int n = arr.length;
        leftRotate(arr, 2);
        for (int i=0; i<n; i++)
            System.out.print(arr[i] + " ");
    }
}
