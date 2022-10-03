public class InsertionSort {
    public static void main(String[] args) {
        int [] arr = {2,6,1,3,8,5};
        for(int i=1;i<arr.length;i++){
            int tp = arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>tp){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=tp;
        }
        for(int no : arr){
            System.out.println(no);
        }
    }
}
