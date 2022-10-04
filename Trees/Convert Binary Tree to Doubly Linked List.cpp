struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public: 
    void leftNode(Node* root, stack<Node*>&st)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    Node * bToDLL(Node *root)
    {
        stack<Node*> st;
        leftNode(root,st);
        Node *d=newNode(-1), *p=d;
        while(!st.empty())
        {
            Node *node=st.top();
            st.pop();
            p->right=node;
            node->left=p;
            p=node;
            leftNode(node->right,st);
        }
        Node *head=d->right;
        head->left=NULL;
        p->right=NULL;
        delete(d);
        return head;
    }
};

