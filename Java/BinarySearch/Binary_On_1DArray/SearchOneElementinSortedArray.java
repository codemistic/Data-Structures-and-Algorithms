package binary.on.onedarray;

public class SearchOneElementinSortedArray {
    public void findUniqueElement() {
        int arr[] = {1, 1, 2, 3, 3, 4, 4, 5, 5};
        int low = 0;
        int high = arr.length - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        System.out.println(arr[low]);
    }
}
