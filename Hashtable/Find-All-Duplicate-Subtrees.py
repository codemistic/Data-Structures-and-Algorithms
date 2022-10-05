# Python3 program to find averages of
# all levels in a binary tree.

# Helper function that allocates a
# new node with the given data and
# None left and right pointers.
class newNode:
	def __init__(self, data):
		self.data = data
		self.left = self.right = None

def inorder(node, m):
	if (not node):
		return ""

	Str = "("
	Str += inorder(node.left, m)
	Str += str(node.data)
	Str += inorder(node.right, m)
	Str += ")"

	# Subtree already present (Note that
	# we use unordered_map instead of
	# unordered_set because we want to print
	# multiple duplicates only once, consider
	# example of 4 in above subtree, it
	# should be printed only once.
	if (Str in m and m[Str] == 1):
		print(node.data, end = " ")
	if Str in m:
		m[Str] += 1
	else:
		m[Str] = 1

	return Str

# Wrapper over inorder()
def printAllDups(root):
	m = {}
	inorder(root, m)

# Driver code
if __name__ == '__main__':
	root = None
	root = newNode(1)
	root.left = newNode(2)
	root.right = newNode(3)
	root.left.left = newNode(4)
	root.right.left = newNode(2)
	root.right.left.left = newNode(4)
	root.right.right = newNode(4)
	printAllDups(root)

