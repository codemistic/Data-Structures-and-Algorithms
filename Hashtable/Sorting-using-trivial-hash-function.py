# Python3 program to sort an array
# using hash function


def sortUsingHash(a, n):

	# find the maximum element
	Max = max(a)

	# create a hash function upto
	# the max size
	Hash = [0] * (Max + 1)

	# traverse through all the elements
	# and keep a count
	for i in range(0, n):
		Hash[a[i]] += 1

	# Traverse upto all elements and check
	# if it is present or not. If it is
	# present, then print the element the
	# number of times it's present. Once we
	# have printed n times, that means we
	# have printed n elements so break out
	# of the loop
	for i in range(0, Max + 1):

		# if present
		if Hash[i] != 0:

			# print the element that number
			# of times it's present
			for j in range(0, Hash[i]):
				print(i, end=" ")


# Driver Code
if __name__ == "__main__":

	a = [9, 4, 3, 2, 5, 2, 1, 0, 4,
		3, 5, 10, 15, 12, 18, 20, 19]
	n = len(a)

	sortUsingHash(a, n)
  
#This code is given by Aman.
