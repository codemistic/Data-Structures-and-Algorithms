package com.company;

import java.util.Scanner;

public class Leetcode1095 {
    public static void main(String[] args) {
        int[] arr={1,3,6,7,9,15,17,14,10,5,-5};
        int target=-5;
        int ans=search(arr,target);
        System.out.println("Index="+ans);
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

    static int search(int[] arr, int target) {
        if(arr.length==0){
            return -1;
        }

        int peak=peakIndex(arr);

        if(arr[peak]==target){
            return peak;
        }

        int start = 0, end = peak - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target > arr[mid]) {
                start = mid + 1;
            } else if (target < arr[mid]) {
                end = mid - 1;
            } else if (target == arr[mid]) {
                return mid;
            }
        }

         start = peak+1; end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target > arr[mid]) {
                end = mid - 1;
            } else if (target < arr[mid]) {
                start = mid + 1;
            } else if (target == arr[mid]) {
                return mid;
            }
        }
        return -1;
    }
    }