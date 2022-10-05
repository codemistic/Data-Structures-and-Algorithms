package com.company;

public class Leetcode34 {
    public static void main(String[] args) {
        int[] arr={2,5,7,9,9,9,9,10,12,16};
        int target=9;
        int first=search(arr,target,true);
        int last=search(arr,target,false);
        System.out.println("First Occurence At="+first);
        System.out.println("Last Occurence At="+last);

    }

    static int search(int[] arr, int target,boolean isStart){
        int start=0,end=arr.length-1;int ans=-1;
        while(end>=start){
            int mid=start+(end-start)/2;
            if(target>arr[mid]){
                start=mid+1;
            }
            else if(target<arr[mid]){
                end=mid-1;
            }
            else if(target==arr[mid]){
                ans=mid;
                if(isStart){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return ans;
    }
}