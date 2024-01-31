# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.

# Example 1:

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


class Solution:
    def twoSum(self, num:list[int], target: int)-> list[int]:
        for i in range(len(num)):
            for j in range(i+1, len(num)):
                if num[i] + num[j] == target:
                    return [i, j]
                
# general_solution = Solution()
# print(general_solution.twoSum([2,7,1,11], 9))

# This code taking way too much runtime because of O(n^2)
                
# We will try another approch which will be Hashmap
                

class Solution2:
    def Two_Sum(self, num: list[int], target:int)->list[int]:
        saw = {}

        for i, num in enumerate(num):
            if target - num in saw:
                return [saw[target-num], i]
            elif num not in saw:
                saw[num] = i
            

# hashmap = Solution2()
# print(hashmap.Two_Sum([2,1,11,23,7], 9))
                

# Used binary search Algorithm 
                



class Solution3:
    def Twosum(self, num: list[int], target: int) -> list[int]:
        # Create a list of tuples (original number, index)
        num_with_indices = [(num[i], i) for i in range(len(num))]
        print(num_with_indices)
        # Sort the list of tuples based on the numbers
        num_with_indices.sort()
        # num_with_indices.sort()
        
        # print(num_with_indices)
        low = 0
        high = len(num) - 1

        while low <= high:
            current_sum = num_with_indices[low][0] + num_with_indices[high][0]

            if current_sum < target:
                low += 1
            elif current_sum > target:
                high -= 1
            else:
                return [num_with_indices[low][1], num_with_indices[high][1]]

        return [-1, -1]  # Return [-1, -1] if no solution is found





hashmap = Solution3()
print(hashmap.Twosum([2, 3, 23, 7], 9))