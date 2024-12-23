def kadanes_algorithm(arr):
    """Standard Kadane's Algorithm for maximum sum subarray."""
    max_ending_here = max_so_far = arr[0]
    
    for num in arr[1:]:
        max_ending_here = max(num, max_ending_here + num)
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far

def max_circular_subarray(arr):
    """Kadane's Algorithm variation for circular arrays."""
    max_kadane = kadanes_algorithm(arr)
    
    # Compute total array sum
    total_sum = sum(arr)
    
    # Invert the array elements
    inverted_arr = [-x for x in arr]
    
    # Find the maximum sum of the inverted array (minimum subarray sum)
    max_inverted_kadane = kadanes_algorithm(inverted_arr)
    
    # The maximum circular sum is total_sum + max_inverted_kadane
    # If max_inverted_kadane is equal to total_sum, it means all elements are negative
    max_circular = total_sum + max_inverted_kadane if max_inverted_kadane != -total_sum else max_kadane
    
    return max(max_kadane, max_circular)

# Example usage
arr = [1, -2, 4, -3]
print("Maximum sum subarray (circular):", max_circular_subarray(arr))