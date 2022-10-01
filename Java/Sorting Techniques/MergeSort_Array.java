/**
 * Program to Sort an Array using Merge Sort
 */
public class MergeSort_Array {

    public static void main(String[] args) {
        int arr[] = {3,5,0,2,9,1,10,0,5,5,9,8};
        int n = arr.length;

        mergsort(arr, 0, n-1);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
    }

    //Recursive Function
    public static void mergsort(int arr[],int s, int e) {
        if(s>=e)
            return;
        
        int mid = (s+e)/2;

        //left sort
        mergsort(arr, s, mid);

        //right sort
        mergsort(arr, mid+1, e);

        //merge the arrays
        merge(arr, s, e);
    }

    public static void merge(int arr[], int s, int e) {
        int mid = (s+e)/2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        int ar1[] = new int[len1];
        int ar2[] = new int[len2];

        //Copying the values of First array
        int k = s;
        for (int i = 0; i < len1; i++) {
            ar1[i] = arr[k++];
        }

        //Copying the values of Second Array
        k = mid+1;
        for (int i = 0; i < len2; i++) {
            ar2[i] = arr[k++];
        }

        //Sorting the arrays and merging it
        int ind1 = 0, ind2=0;
        k=s;
        while (ind1<len1 && ind2<len2) {
            if(ar1[ind1]<ar2[ind2])
                arr[k++] = ar1[ind1++];
            else
                arr[k++] = ar2[ind2++];
        }

        while (ind1<len1) {
            arr[k++] = ar1[ind1++];
        }
        
        while (ind2<len2) {
            arr[k++] = ar2[ind2++];
        }
    }
}