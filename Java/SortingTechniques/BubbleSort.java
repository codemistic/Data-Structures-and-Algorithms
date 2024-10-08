package SortingAlgorithms;

import java.util.Arrays;

public class BubbleSortAlgorithm {
    public static void main(String[] args) {
        /*
         Algorithm :
         1. Concept of bubble sort : at every step you are comparing
            adjacent elements

            --> STEP-1 <-
         2. * Consider an array : {3,1,5,4,2}
            Now, we are like hey is 3>1, yes then swap it.
            * now the array would be : {1,3,5,4,2}
             is 3>5 NO, move ahead ; then is 5>4 ,YES swap it
             * now the array would be : {1,3,4,5,2}
              is 5>2 ,YES swap it .
             * now the final array would be : {1,3,4,2,5}
           --> For the first round of the bubble sort we will
             compare till the last element of the array

             *** The above was Pass No.01 ***
             With pass no. 1 , the largest element is at the end

             Q. Why Bubble sort ?
             ans -> we can see that on comparing the adjacent element
                   one time throughout the array(i.e, Pass no.01)
                   the largest element of the array came to  the end

            *** Now again Pass No.02 ***
            With pass no. 2 ,the 2nd largest element is at the end

              arr = {1,3,4,2,5}
              is 1>3 no
              is 3>4 no
              is 4>2 yes ,Swap it
              is 2>5 no

              this time the final array would be : {1,3,2,4,5}

              *** Now again Pass No.03 ***
              With pass no. 3 , 3rd the largest element is at the end
              this will be continued as the passes increases.

              // Intuition :
               At every step the largest element of that particular
               array is at the last -> This is bubble sort algorithm
               --> Also known as "sinking sort or exchanging sort"


              arr ={1,3,2,4,5}
              is 1>3 No
              is 3>2 yes, Swap it
              is 2>4 no
              is 4>5 no

              this time the final array would be : {1,2,3,4,5}
              Now the array is completely sorted :

              Time complexity:
              Best case : if for a particular Ith pass the value of j never swaps then it will be the best case\
                          O(N) --> Is the time complexity in the best case

              Worst case : if the array is given in descending order :
                          O(N*N) --> is the time complexity in the worst case

                          // --> For complete understanding checkout my notes.

             */

        int[] arr= {5,4,3,2,1};
        bubble(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void bubble(int[] arr) {
        boolean swapped ;
        // run the loop n-1 times
        for(int i=0;i< arr.length;i++) {
                swapped = false;
              // for each step,max items will come at the last respective index
            for(int j=1;j<arr.length-i;j++) {
             // swap if the item is smaller than the previous one
                if(arr[j-1]>arr[j]) {
                    // swap
                    int temp = arr[j-1];
                    arr[j-1]= arr[j];
                    arr[j] = temp;
                    swapped = true;

}
            }
// if you did not swap for a particular value of i, it means the array is sorted
// hence stop searching further.
         //   if(swapped== false) { this is also fine
            if(!swapped) {
                break;
            }
        }

    }
}
