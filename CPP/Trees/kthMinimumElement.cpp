// from a given BST, the program will find out the kth smallest element (hardcoded)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}
void saveNode(struct node *root, vector<struct node *> &nodes)
{
    if (root == NULL)
        return;

    saveNode(root->left, nodes);
    nodes.push_back(root);
    saveNode(root->right, nodes);
}

int findKthMin(struct node *root, int k)
{
    vector<struct node *> nodes;
    saveNode(root, nodes);

    return nodes[k - 1]->key;
}

int main()
{
    int k = 1;
    struct node *root = NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 1);
    insert(root, 9);
    insert(root, 5);
    insert(root, 8);
    cout << "The " << k << "st smallest element in Binary search tree is " << findKthMin(root, k);
}
