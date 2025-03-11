#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
    int data;
    Tree *left, *right;

    Tree(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to compute the bottom view using BFS (level order traversal)
void bottomView(Tree* root) {
    if (!root) return;

    map<int, int> m; // Stores horizontal distance and node value
    queue<pair<Tree*, int>> q; // Queue for BFS traversal

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Overwrite the value at each HD since the last one is the bottom view
        m[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Print the bottom view
    for (auto [hd, value] : m) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    Tree* root = new Tree(20);
    root->left = new Tree(8);
    root->right = new Tree(22);
    root->left->left = new Tree(5);
    root->left->right = new Tree(3);
    root->right->left = new Tree(4);
    root->right->right = new Tree(25);
    root->left->right->left = new Tree(10);
    root->left->right->right = new Tree(14);

    bottomView(root);

    return 0;
}
