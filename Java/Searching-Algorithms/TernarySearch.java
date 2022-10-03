package tryyy;

import java.util.Scanner;

class TernarySearch {
    static int ternarySearch(int l, int r, int key, int[] ar)
    {
        if (r >= l) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            if (ar[mid1] == key) {
                return mid1;
            }
            if (ar[mid2] == key) {
                return mid2;
            }
            if (key < ar[mid1]) {
                return ternarySearch(l, mid1 - 1, key, ar);
            }
            else if (key > ar[mid2]) {
                return ternarySearch(mid2 + 1, r, key, ar);
            }
            else {
                return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
            }
        }
        return -1;
    }
    public static void main(String[] args)
    {
        int l, r, p, key;
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] ar=new int[n];
        for(int i=0;i<n;i++)
            ar[i]=sc.nextInt();
        l = 0;
        r = n-1;
        System.out.println("Enter Target Key: ");
        key=sc.nextInt();
        p = ternarySearch(l, r, key, ar);
        System.out.println("Index of " + key + " is " + p);
    }
}
