class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* leftmost = root;  // Start at the root level

        while (leftmost) {
            Node* dummy = new Node(0);  // Dummy node for next level
            Node* temp = dummy;  // Pointer to build next level links

            Node* curr = leftmost;
            while (curr) {
                if (curr->left) {
                    temp->next = curr->left;
                    temp = temp->next;
                }
                if (curr->right) {
                    temp->next = curr->right;
                    temp = temp->next;
                }
                curr = curr->next;  // Move to next node in current level
            }

            leftmost = dummy->next;  // Move to next level
            delete dummy; // Free dummy node
        }

        return root;
    }
};
