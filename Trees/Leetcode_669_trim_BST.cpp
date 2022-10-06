#include <bits/stdc++.h>
#include <string>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    public:
    TreeNode(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode* createTree(int val)
    {
        if(this==NULL)
        {
            TreeNode *newLeaf = new TreeNode(val);
            return newLeaf;
        }
        else
        {
            TreeNode *temp=NULL;
            if(this->val>val)
            {
                temp=this->left->createTree(val);
                this->left=temp;
            }
            else
            {
                temp=this->right->createTree(val);
                this->right=temp;
            }
            return(this);
        }
    }
    
    void preOrder()
    {
       if(this!=NULL)
        {
            cout<<this->val<<" , ";
            this->left->preOrder();
            this->right->preOrder();
        }
    }

    TreeNode* trimTree(int low, int high)
    {
        if(this==nullptr)
        return nullptr;
        else
        {
            if(this->val>=low&&this->val<=high)
            {
                this->left=this->left->trimTree(low,high);
                this->right=this->right->trimTree(low,high);
                return this;
            }
            else if(this->val>high)
            {
                this->right=nullptr;
                return(this->left->trimTree(low,high));
            }
            else
            {
                this->left=nullptr;
                return(this->right->trimTree(low,high));
            }
        }
    }
};

int main()
{
    string s, t="";
    int l,u,temp;
    getline(cin,s); 
    s+=",";    
    ws(cin);
    cin>>l>>u;
    vector<int>elements;
    for(int i=0;i<s.length();i++)        //extracting the integers, excluding the brackets and ','
    {
       if(s[i]==',')    //s[i] as string is treated as an array, s.at(i) would be the same
       {
           elements.push_back(stoi(t));     //stoi(<string-name>) is used for converting strings to integers
           t="";
       }
       else
       t+=s[i];
    }
    TreeNode *root=nullptr;
    for(int i: elements)
    root=root->createTree(i);
    cout<<"The Tree: "<<endl;
    root->preOrder();
    TreeNode *trimRoot = root->trimTree(l,u);
    cout<<"The Trimmed Tree: "<<endl;
    trimRoot->preOrder();
}
