/*Problem
56. Merge Intervals (LEETCODE)
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.

Meaning -> For example, if we have 2 meetings, one is scheduled from 7am-8am and the other one is from 7:30am-9am. Then we can merge these
2 meetings 2 get 1 -> (7am-9am).

How to implement -> We'll be using Stack data structure to solve this problem.

IDEOLOGY -> Sort the given elements of the array. Then merge 2 meetings if start time of the second meeting is encountered before the end time of the first meeting. */


class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b)-> Integer.compare(a[0], b[0]));    //This sorting will sort the meetings according to their start time.

        Stack<int[]> st = new Stack<>();
        st.push(intervals[0]);    //Initially, we'll push the first meeting element into the stack.

        for(int i = 1; i < intervals.length; i++){
            if(st.peek()[1] >= intervals[i][0]){
                int[] arr = st.pop();
                arr[1] = Math.max(arr[1], intervals[i][1]);
                st.push(arr);
            } else {
                st.push(intervals[i]);
            }
        }
        int[][] ans = new int[st.size()][2];
        int index = ans.length-1;
        while(index >= 0){
            ans[index] = st.pop();
            index--;
        }
        return ans;
    }
}
