/*
Sliding Window Median
https://leetcode.com/problems/sliding-window-median/
*/

class Solution {
    PriorityQueue<Integer> maxHeap=new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> minHeap=new PriorityQueue<>();
    
    public double[] medianSlidingWindow(int[] nums, int k) {
        int i=0,j=0;
        double[] ans=new double[nums.length-k+1];
        
        while(j<nums.length){
            if(maxHeap.isEmpty() || maxHeap.peek()>=nums[j])
                maxHeap.offer(nums[j]);
            else minHeap.offer(nums[j]);
            
            if(maxHeap.size()>minHeap.size()+1)
                minHeap.offer(maxHeap.poll());
            else if(maxHeap.size()<minHeap.size())
                maxHeap.offer(minHeap.poll());
                
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(maxHeap.size()==minHeap.size())
                    ans[i]=maxHeap.peek()/2.0+minHeap.peek()/2.0;
                else ans[i]=maxHeap.peek();
                
//                 remove ith element
                if(nums[i]<=maxHeap.peek())
                    maxHeap.remove(nums[i]);
                else minHeap.remove(nums[i]);
                
                if(maxHeap.size()>minHeap.size()+1)
                    minHeap.offer(maxHeap.poll());
                else if(maxHeap.size()<minHeap.size())
                    maxHeap.offer(minHeap.poll());
                
                i++;j++;
            }
        }
        return ans;
    }
    
}
