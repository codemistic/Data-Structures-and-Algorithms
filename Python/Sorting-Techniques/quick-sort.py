def quicksort(array):
    size = len(array)
    if size==0 or size==1:
        return array

    pivot = array.pop()
    lesser = [x for x in array if x<pivot]
    greater = [x for x in array if x>=pivot]

    result = quicksort(lesser)
    result.append(pivot)
    result.extend(quicksort(greater))

    return result


if __name__ == "__main__":
    array = [9, 2, 6, 4, 6, 1, 10, 5]
    print("Input is {}".format(array))
    print("Sorted output is: {}".format(quicksort(array)))
