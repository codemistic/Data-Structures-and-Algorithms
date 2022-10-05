package LinearSearchAlgorithm;

public class Q1Searching {
    public static void main(String[] args) {

        // in Linear Search :
        // In the best case O(1) : the element will be found be
        // found  on the first try when 1st element == target {i.e,
        // It will make only 1 comparison }
        // In the worst case O(N) : It will make n
        // comparison only  where n is the size of the array



        // search in the array :return the index if item found
        // otherwise if the item not found return -1
        int[] arr ={22,44,97,67,92,17};
        int ans = linearSearch(arr,97);
        System.out.println(ans);
    }

    static int linearSearch(int[] arr, int target) {
        if(arr.length ==0){
            return -1;
        }

        // run a for loop
        for(int index=0;index<arr.length;index++) {
          // check for element at every index if it is = target
            if(arr[index] == target){
                return index;
            }
        }
        // this line will execute if none of the return statements above have executed
        // hence the target not found
        return -1;
    }
}
