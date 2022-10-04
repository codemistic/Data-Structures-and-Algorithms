package com.company;

public class Leetcode744 {
    public static void main(String[] args) {
        char[] arr={'c','f','j'};
        char target='c';

        int ans=ceiling(arr,target);

        if(ans==-1){
            System.out.println("Empty Array");
        }
        else
            System.out.println("Ceiling="+arr[ans]);
    }

    static int ceiling(char[] arr, char target){
        int start=0,end=arr.length-1;
        if(arr.length==0){
            return -1;
        }

        while(end>=start){
            int mid=start+(end-start)/2;

            if(target>=arr[mid]){
                start=mid+1;
            }
            else if(target<arr[mid]){
                end=mid-1;
            }
        }
        return start%arr.length;
    }
}
