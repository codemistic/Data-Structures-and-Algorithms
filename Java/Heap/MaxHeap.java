public class MaxHeap {
    //Util Functions

    //resize function to increase our heap's size in case of an overflow
    Integer[] resize(Integer[] arr, int cap){
        Integer[] temp = new Integer[cap];
        System.arraycopy(arr, 0, temp, 0, size+1);
        arr = temp;
        return arr;
    }

    //swap function for switching elements
    void swap(Integer s, Integer l){
        Integer temp = mHeap[s];
        mHeap[s] = mHeap[l];
        mHeap[l] = temp;
    }

    //bottom up re-heapify after inserting element(swim)
    private void bottomUp(int elemIndex){
        while(elemIndex > 1 && mHeap[elemIndex / 2] < mHeap[elemIndex]){
            swap(elemIndex, elemIndex / 2);
            elemIndex = elemIndex / 2;
        }
    }

    //top down re-heapify after deleting element(sink)
    private void topDown(int elemIndex){
        while(2 * elemIndex <= size){
            int childIndex = 2 * elemIndex;
            if(childIndex < size && mHeap[childIndex] < mHeap[childIndex + 1]){
                ++childIndex;
            }
            if(mHeap[elemIndex] >= mHeap[childIndex]){
                break;
            }
            swap(elemIndex, childIndex);
            elemIndex = childIndex;

        }
    }

    //Driver Code
    Integer[] mHeap;
    int size;

    //method to initialise our max heap
    public MaxHeap(int size) {
        mHeap = new Integer[size + 1];
        this.size = 0;
    }

    //method to print max heap
    public void print(){
        System.out.print("Max Heap : ");
        for(int elem = 1 ; elem < mHeap.length ; elem++){
            if(mHeap[elem] != null) {
                System.out.printf("%s ", mHeap[elem]);
            }
        }
        System.out.println();
    }

    //method to insert elements into max heap
    public void add(int element){
        if(size == mHeap.length - 1) {
            mHeap = resize(mHeap, 2 * mHeap.length);
        }
        ++size;
        mHeap[size] = element;
        bottomUp(size);

    }

    //method for extracting elements from MaxHeap
    public Integer poll() {
        Integer max = mHeap[1];
        if(size==0) return null;
        swap(1, size);
        --size;
        topDown(1);
        mHeap[size + 1] = null;
        if(size > 0 && (size == (mHeap.length - 1) / 4)){
           mHeap = resize(mHeap, mHeap.length / 2);
        }
        return max;
    }

    //Initialising Code
    public static void main(String[] args){
        MaxHeap pq = new MaxHeap(7);
        pq.add(56);
        pq.print();
        pq.add(97);
        pq.add(23);
        pq.add(1);
        pq.print();
        pq.add(172);
        pq.print();
        System.out.println("Extracting max: "+pq.poll());
        System.out.println("Extracting max: "+pq.poll());
        System.out.println("Extracting max: "+pq.poll());
        System.out.println("Extracting max: "+pq.poll());
        System.out.println("Extracting max: "+pq.poll());
    }
}
