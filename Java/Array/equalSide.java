/**
find an index N where the sum of the integers to the left of N is equal to the sum of the integers to the right of N. 
If there is no index that would make this happen, return -1.

I/P:[1,2,3,4,3,2,1]

O/P: 3
*/


public class equalSide {
  public static int findEvenIndex(int[] arr) {
    // your code
    int sum = 0, eq = 0;
    for (int i = 0; i < arr.length; i++){ 
      sum += arr[i];
    }
    for(int i = 0; i < arr.length; i++){
      if (eq == sum - arr[i]){ 
        return i;
      }
      eq += arr[i];
      sum -= arr[i];
    }
    return -1;
  }
  
  public static void main(String[] args){
    int[] array = {1,2,3,4,3,2,1};
    int sideVal = findEvenIndex(array);
    System.out.println(sideVal);
  }
}
