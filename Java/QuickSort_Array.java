
/* Program to Sort an Array Using the QuickSort Sorting Algorithm */

public class QuickSort_Array {
    public static void main(String[] args) {
        int arr[] = {1000,6,3,5,2,8,9,12,200};
        int n = arr.length;
        quickSort(arr, 0, n-1);
        
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
    }

    public static void quickSort(int arr[], int low, int high) {
        if(low < high)
        {
            int pindex = partition(arr, low, high);

            quickSort(arr, low, pindex-1);
            quickSort(arr, pindex+1, high);
        }
    }
    public static int partition(int arr[], int low, int high) {
        int piv = arr[high];
        int i=low-1;

        for (int j = low; j < high; j++) {
            if(arr[j]<piv)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        int temp = arr[i];
        arr[i] = piv;
        arr[high] = temp;

        return i;
    }
}
