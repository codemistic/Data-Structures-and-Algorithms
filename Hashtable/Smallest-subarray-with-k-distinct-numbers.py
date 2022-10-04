# Python 3 program to find minimum range
# that contains exactly k distinct numbers.

# Prints the minimum range that contains
# exactly k distinct numbers.
def minRange(arr, n, k):

	l = 0
	r = n

	# Consider every element as
	# starting point.
	for i in range(n):

		# Find the smallest window starting
		# with arr[i] and containing exactly
		# k distinct elements.
		s = []
		for j in range(i, n) :
			s.append(arr[j])
			if (len(s) == k):
				if ((j - i) < (r - l)) :
					r = j
					l = i
				
				break

		# There are less than k distinct
		# elements now, so no need to continue.
		if (j == n):
			break

	# If there was no window with k distinct
	# elements (k is greater than total
	# distinct elements)
	if (l == 0 and r == n):
		print("Invalid k")
	else:
		print(l, r)

# Driver code
if __name__ == "__main__":
	
	arr = [ 1, 2, 3, 4, 5 ]
	n = len(arr)
	k = 3
	minRange(arr, n, k)


