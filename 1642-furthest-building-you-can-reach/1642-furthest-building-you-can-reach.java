import java.util.PriorityQueue;

class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // Min heap to track used bricks
        int i = 0;
        
        for (; i < heights.length - 1; i++) {
            int distance = heights[i + 1] - heights[i];

            if (distance > 0) {
                pq.add(distance);
            }

            // If we have used more ladders than available, replace the smallest ladder use with bricks
            if (pq.size() > ladders) {
                bricks -= pq.poll(); // Convert the smallest ladder usage into bricks
            }

            // If bricks are exhausted, return the last possible building index
            if (bricks < 0) {
                return i;
            }
        }

        return i; // Reached the last building
    }
}
