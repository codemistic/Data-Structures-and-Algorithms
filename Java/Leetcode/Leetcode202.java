package com.company;

public class Leetcode202 {
    public static void main(String[] args) {
        int n=19;
        boolean answer=happyNumber(n);
        System.out.println(answer);

    }

//    Linked List will be used in this bcoz cycle is forming. We can use slow and fast pointer method in this.
    public static boolean happyNumber(int n){
        int slow=n;
        int fast=n;

        do {
            slow=square(slow);
            fast=square(square(fast));
        } while (slow!=fast);

        if(slow==1){
            return true;
        }
        return false;
    }

    private static int square(int n){
        int digit = 0;
        int sum=0;
        while (n!=0){
            digit=n%10;
            sum=digit*digit+sum;
            n=n/10;
        }
        return sum;
    }
}