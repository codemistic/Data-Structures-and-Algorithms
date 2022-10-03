// check if a Tree is foldable or not

// approach:
// If one of the two trees is empty, return false; if both are empty, return true
// If one of the subtree is found out to be mirror of the other one, return true

bool find(node *node1, node *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    return find(node1->left, node2->right) && find(node1->right, node2->left);
}

bool foldableCheck(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    return find(root->left, root->right);
}
