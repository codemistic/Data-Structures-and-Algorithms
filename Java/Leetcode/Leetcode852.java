package com.company;

public class Leetcode852 {
    public static void main(String[] args) {
        int arr[]={2,5,7,9,8,6,2,1};
    int ans=peakIndex(arr);
        System.out.println(arr[ans]);
    }
    static int peakIndex(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid+1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

}
