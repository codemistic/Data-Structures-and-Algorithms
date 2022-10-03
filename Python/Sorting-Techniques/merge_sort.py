def merge_sort(values):
    if len(values) <= 1:
        return values
    else:
        middle_index = len(values) // 2

        left_half = merge_sort(values[:middle_index])
        right_half = merge_sort(values[middle_index:])

        sorted_values = []
        left_index = 0; right_index = 0

        while left_index < len(left_half) and right_index < len(right_half):
            if left_half[left_index] <= right_half[right_index]:
                sorted_values.append(left_half[left_index])
                left_index += 1
            else:
                sorted_values.append(right_half[right_index])
                right_index += 1

        
        sorted_values += left_half[left_index:]
        sorted_values += right_half[right_index:]

        return sorted_values