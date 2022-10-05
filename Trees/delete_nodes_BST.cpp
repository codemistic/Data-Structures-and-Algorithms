#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:

    int val;
    Tree *left;
    Tree *right;

public:

    //class constructor called when any object or pointer is created without any parameter.
    Tree()                          
    {
        val=0;
        left=nullptr;
        right=nullptr;
    }

     //class constructor called when an object or pointer is called while passing an argument (val). 
    Tree(int val)                  
    {
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }

    //builds a Binary Tree taking (int) value as an argument and returns the root to the tree built. 
    Tree* buildTree(int val)
    {
        if(this==nullptr)
        {
            Tree *temp = new Tree(val);
            return temp;
        }
        else
        {
            Tree *temp=nullptr;
            if(this->val>val)
            {
                temp=this->left->buildTree(val);
                this->left=temp;
            }
            else
            {
                temp=this->right->buildTree(val);
                this->right=temp;
            }
            return this;
        }
    }
    
    //RECURSIVE DFS PREORDER
    void preOrder()     
    {
        if(this!=nullptr)
        {
            cout<<this->val<<",";
            this->left->preOrder();
            this->right->preOrder();
        }
    }
};

Tree* deleteNode(Tree *root, int val)
{
    if(root==nullptr)
    return nullptr;
    else
    {
        if(root->val>val)
        root->left=deleteNode(root->left,val);
        else if(root->val<val)
        root->right=deleteNode(root->right,val);
        else
        {
            if(root->left!=nullptr)
            {
                Tree *temp=root->left;
                Tree *trav=temp->right;
                if(trav==nullptr)
                {
                    temp->right=root->right;
                    root=temp;
                }
                else
                {
                    while(trav->right!=nullptr)
                    {
                        temp=trav;
                        trav=trav->right;
                    }
                    temp->right=trav->left;
                    root->val=trav->val;
                    trav->left=NULL;
                }
            }
            else if(root->right!=nullptr)
            {
                Tree *temp=root->right;
                Tree *trav=temp->left;
                if(trav==nullptr)
                {
                    temp->left=root->left;
                    root=temp;
                }
                else
                {
                    while(trav->left!=nullptr)
                    {
                        temp=trav;
                        trav=trav->left;
                    }
                    temp->left=trav->right;
                    root->val=trav->val;
                    trav->right=NULL;
                }
            }
            else
            root=nullptr;
        }
        return root;
    }
}

int main()
{
    vector<int>test={8,5,3,6,11,10,9,12};
    Tree *root=nullptr;
    for(int i:test)
    root=root->buildTree(i);
    cout<<"The tree:  ";
    root->preOrder();
    root=deleteNode(root,6);
    cout<<"\nThe tree after deletion:  ";
    root->preOrder();
}
