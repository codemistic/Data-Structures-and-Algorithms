def insertionSort(arr):
    for i in range(1, len(arr)):  #loop through array
        key = arr[i]      # store current element in key
        j = i-1     # mark j as iteration -1
        while j >= 0 and key < arr[j] :   #check if arr[j]>key and j<=0 then swap
                arr[j + 1] = arr[j]
                j -= 1    #decrement j
        arr[j + 1] = key  #set a[j+1] = key
