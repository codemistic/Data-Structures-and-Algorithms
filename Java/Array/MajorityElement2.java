package manas.pkg1.LeetCode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MajorityElem2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int[] arr=new int[n];
        int i;
        for(i=0;i<n;i++)
            arr[i]=Integer.parseInt(br.readLine());
        System.out.println(Arrays.toString(arr));
        int ele1=Integer.MIN_VALUE,ele2=Integer.MIN_VALUE,count1=0,count2=0;
        for(i=0;i<n;i++) {
            if (ele1 == arr[i]) count1++;
            else if (ele2 == arr[i]) count2++;
            else if (count1 == 0) {
                ele1 = arr[i];
                count1++;
            }
            else if (count2 == 0) {
                ele2 = arr[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
            count1=0;
            count2=0;
            for (i=0;i<n;i++){
                if(arr[i]==ele1) count1++;
                if(arr[i] == ele2) count2++;
            }
            if(count1 > n/3) System.out.println(ele1);
            if(count2 > n/3) System.out.println(ele2);
    }
}
