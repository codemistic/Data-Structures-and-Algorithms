def countingSort(unsortedArr):
    highest = 0
    for i in unsortedArr:
        if i > highest:
            highest = i
    tempArr = [0] * (highest + 1)
    for i in unsortedArr:
        tempArr[i] += 1
    for i in range(len(tempArr)):
        if i != 0:
            tempArr[i] += tempArr[i - 1]
    sortedArr = [0] * len(unsortedArr)
    for i in unsortedArr:
        sortedArr[tempArr[i] - 1] = i
        tempArr[i] -= 1
    print(sortedArr)

countingSort([4, 7, 9, 3, 1, 5, 2, 8, 0, 6])