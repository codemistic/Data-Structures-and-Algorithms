class Solution:
    def getSkyline(self, A: List[List[int]]) -> List[List[int]]:
        n = len(A)
        # If the given array of building contains only 1 or less building, we can
        # directly return a corresponding skyline.
        if n == 0: return []
        if n == 1: return [[A[0][0], A[0][2]], [A[0][1], 0]]

        # Otherwise, we shall recursively divide the buildings and merge the skylines.
        # Cut the given skyline into two halves, get skyline from each half and merge
        # them into a single skyline.
        left_skyline = self.getSkyline(A[: n // 2])
        right_skyline = self.getSkyline(A[n // 2 :])  
        return self.merge_sky(left_skyline, right_skyline)
        
    def merge_sky(self, left_skyline, right_skyline):
        # Initalize left_pos=0, right_pos=0 as the pointer of left_skyline and right_skyline.
        # Since we start from the left ground, thus the previous height from 
        # left_skyline and right_skyline are 0.
        answer = []
        left_pos, right_pos = 0, 0
        left_prev_height, right_prev_height = 0, 0

        # Now we start to iterate over both skylines.
        while left_pos < len(left_skyline) and right_pos < len(right_skyline):
            next_left_x = left_skyline[left_pos][0]
            next_right_x = right_skyline[right_pos][0]
            
            # If we meet left_skyline key point first, our current height changes to the
            # larger one between height on left skyline and the previous height on right
            # skyline. Update the previous height from left_skyline and increment left_pos by 1.
            if next_left_x < next_right_x:
                left_prev_height = left_skyline[left_pos][1]
                cur_x = next_left_x
                cur_y = max(left_prev_height, right_prev_height)
                left_pos += 1
           

            # If we meet right_skyline key point first, our current height changes to the
            # larger one between height on right skyline and the previous height on left
            # skyline. Update the previous height from right_skyline and increment right_pos by 1.
            elif next_left_x > next_right_x:
                right_prev_height = right_skyline[right_pos][1]
                cur_x = next_right_x
                cur_y = max(left_prev_height, right_prev_height)
                right_pos += 1

            # If both skyline key points has same x:
            # Our current height is the larger one, update the previous height
            # from left_skyline and right_skyline. Increment both left_pos and right_pos by 1.
            else:
                left_prev_height = left_skyline[left_pos][1]
                right_prev_height = right_skyline[right_pos][1]
                cur_x = next_left_x
                cur_y = max(left_prev_height, right_prev_height)
                left_pos += 1
                right_pos += 1
            
            # Discard those key points that has the same height as the previous one.
            if not answer or answer[-1][1] != cur_y:
                answer.append([cur_x, cur_y])
        
        # If we finish iterating over any skyline, just append the rest of the other
        # skyline to the merged skyline.
        while left_pos < len(left_skyline):
            answer.append(left_skyline[left_pos])
            left_pos += 1
        while right_pos < len(right_skyline):
            answer.append(right_skyline[right_pos])
            right_pos += 1
        return answer       
