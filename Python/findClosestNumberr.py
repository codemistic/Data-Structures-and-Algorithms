def get_closest(val1, val2, t):
    if abs(val1 - t) <= abs(val2 - t):
        return val1
    else:
        return val2


def find_closest(arr, n, t):
    """
    Using Binary Search find the number closest
    to target in the given sorted array
    """
    if t <= arr[0]:
        return arr[0]
    elif t >= arr[n - 1]:
        return arr[n - 1]
    left, right = 0, n
    while left < right:
        mid = (left + right) // 2
        if arr[mid] == t:
            return arr[mid]
        elif t < arr[mid]:
            if mid > 0 and arr[mid - 1] < t:
                return get_closest(arr[mid - 1], arr[mid], t)
            right = mid
        else:
            if mid < n - 1 and arr[mid + 1] > t:
                return get_closest(arr[mid], arr[mid + 1], t)
            left = mid + 1
    return arr[mid]


if __name__ == "__main__":
    array = [1, 2, 4, 5, 6, 6, 8, 9]
    size = len(array)
    target = 7
    print(find_closest(array, size, target))
