def morris_traversal(root):
    current = root
    while current:
        if current.left is None:
            print(current.data)
            current = current.right
        else:
            pre = current.left                       # Find the inorder predecessor of current
            while pre.right and pre.right is not current:
                pre = pre.right
            if pre.right is None:
                pre.right = current                  # Make current as right child of its inorder predecessor
                current = current.left
            else:
                pre.right = None                     # Revert the changes made in the 'if' part to restore the original tree. i.e., fix the right child of predecessor
                print(current.data)
                current = current.right
