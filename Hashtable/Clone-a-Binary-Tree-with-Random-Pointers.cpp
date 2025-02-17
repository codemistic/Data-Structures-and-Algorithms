// // A hashmap based C++ program to clone a binary
// // tree with random pointers
// #include<iostream>
// #include<unordered_map>
// using namespace std;

// /* A binary tree node has data, pointer to left child,
// 	a pointer to right child and a pointer to
// 	random node*/
// struct Node
// {
// 	int key;
// 	struct Node* left, *right, *random;
// };

// /* Helper function that allocates a new Node with the
// given data and NULL left, right and random pointers. */
// Node* newNode(int key)
// {
// 	Node* temp = new Node;
// 	temp->key = key;
// 	temp->random = temp->right = temp->left = NULL;
// 	return (temp);
// }

// /* Given a binary tree, print its Nodes in inorder*/
// void printInorder(Node* node)
// {
// 	if (node == NULL)
// 		return;

// 	/* First recur on left subtree */
// 	printInorder(node->left);

// 	/* then print data of Node and its random */
// 	cout << "[" << node->key << " ";
// 	if (node->random == NULL)
// 		cout << "NULL], ";
// 	else
// 		cout << node->random->key << "], ";

// 	/* now recur on right subtree */
// 	printInorder(node->right);
// }

// /* This function creates clone by copying key
// and left and right pointers. This function also
// stores mapping from given tree node to clone. */
// Node* copyLeftRightNode(Node* treeNode, unordered_map<Node *, Node *> &mymap)
// {
// 	if (treeNode == NULL)
// 		return NULL;
// 	Node* cloneNode = newNode(treeNode->key);
// 	mymap[treeNode] = cloneNode;
// 	cloneNode->left = copyLeftRightNode(treeNode->left, mymap);
// 	cloneNode->right = copyLeftRightNode(treeNode->right, mymap);
// 	return cloneNode;
// }

// // This function copies random node by using the hashmap built by
// // copyLeftRightNode()
// void copyRandom(Node* treeNode, Node* cloneNode, unordered_map<Node *, Node *> &mymap)
// {
// 	if (cloneNode == NULL)
// 		return;
// 	cloneNode->random = mymap[treeNode->random];
// 	copyRandom(treeNode->left, cloneNode->left, mymap);
// 	copyRandom(treeNode->right, cloneNode->right, mymap);
// }

// // This function makes the clone of given tree. It mainly uses
// // copyLeftRightNode() and copyRandom()
// Node* cloneTree(Node* tree)
// {
// 	if (tree == NULL)
// 		return NULL;
// 	unordered_map<Node *, Node *> mymap;
// 	Node* newTree = copyLeftRightNode(tree, mymap);
// 	copyRandom(tree, newTree, mymap);
// 	return newTree;
// }

// /* Driver program to test above functions*/
// int main()
// {
// 	//Test No 1
// 	Node *tree = newNode(1);
// 	tree->left = newNode(2);
// 	tree->right = newNode(3);
// 	tree->left->left = newNode(4);
// 	tree->left->right = newNode(5);
// 	tree->random = tree->left->right;
// 	tree->left->left->random = tree;
// 	tree->left->right->random = tree->right;

// 	// Test No 2
// 	// tree = NULL;

// 	// Test No 3
// 	// tree = newNode(1);

// 	// Test No 4
// 	/* tree = newNode(1);
// 		tree->left = newNode(2);
// 		tree->right = newNode(3);
// 		tree->random = tree->right;
// 		tree->left->random = tree;
// 	*/

// 	cout << "Inorder traversal of original binary tree is: \n";
// 	printInorder(tree);

// 	Node *clone = cloneTree(tree);

// 	cout << "\n\nInorder traversal of cloned binary tree is: \n";
// 	printInorder(clone);

// 	return 0;
// }

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right, *random;
};

// Function to create a new node
Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = temp->random = nullptr;
    return temp;
}

// Step 1: Insert cloned nodes in the tree itself
void insertClones(Node* root) {
    if (!root) return;

    Node* clone = newNode(root->key);
    clone->left = root->left;
    root->left = clone;

    insertClones(clone->left);
    insertClones(root->right);
}

// Step 2: Copy random pointers to cloned nodes
void copyRandomPointers(Node* root) {
    if (!root) return;

    if (root->random)
        root->left->random = root->random->left;

    copyRandomPointers(root->left->left);
    copyRandomPointers(root->right);
}

// Step 3: Separate the cloned tree from the original
Node* extractClone(Node* root) {
    if (!root) return nullptr;

    Node* clone = root->left;
    root->left = clone->left;

    clone->left = extractClone(root->left);
    clone->right = extractClone(root->right);

    return clone;
}

// Clone function that integrates all steps
Node* cloneTree(Node* root) {
    if (!root) return nullptr;

    insertClones(root);        // Step 1: Create interleaved cloned nodes
    copyRandomPointers(root);  // Step 2: Copy random pointers
    return extractClone(root); // Step 3: Separate cloned tree
}

// Inorder traversal to print the tree
void printInorder(Node* node) {
    if (!node) return;

    printInorder(node->left);
    cout << "[" << node->key << " ";
    if (node->random) cout << node->random->key;
    else cout << "NULL";
    cout << "], ";
    printInorder(node->right);
}

// Driver code
int main() {
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;

    cout << "Original Tree Inorder:\n";
    printInorder(tree);

    Node *clone = cloneTree(tree);

    cout << "\n\nCloned Tree Inorder:\n";
    printInorder(clone);

    return 0;
}
