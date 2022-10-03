#include<bits/stdc++.h>
#include"binarytree.h"
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

void printTree(binarytree<int>*root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<":";
    if(root->left)
        cout<<"L"<<root->left->data<<",";
    
    if(root->right)
        cout<<"R"<<root->right->data<<",";

    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

void printlevelwise(binarytree<int>*root)
{
    queue<binarytree<int>*> pendingnode;
    pendingnode.push(root);

    while(pendingnode.size()!=0)
    {
        binarytree<int>*front=pendingnode.front();
        cout<<front->data<<":";
        pendingnode.pop();
        if(front->left)
        {
            cout<<"L"<<front->left->data<<",";
            pendingnode.push(front->left);
        }

        if(front->right)
        {
            cout<<"R"<<front->right->data<<",";
            pendingnode.push(front->right);
        }

        cout<<endl;
        
    }

}

binarytree<int>* takeinput()
{
    int rootdata;
    cout<<"enter data:";
    cin>>rootdata;

    if(rootdata==-1)    
        return NULL;

    binarytree<int>*root=new binarytree<int> (rootdata);
    binarytree<int>*leftchild=takeinput();
    binarytree<int>*rightchild=takeinput();

    root->left=leftchild;
    root->right=rightchild;

    return root;

}


binarytree<int>*takeinputlevelwise()
{
    cout<<"enter root data : ";
    int rootdata;
    cin>>rootdata;
    binarytree<int>*root=new binarytree<int>(rootdata);
    queue<binarytree<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        binarytree<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<endl<<"enter left child of "<<front->data<<" : ";
        int child;
        cin>>child;
        if(child!=-1)
        {
            binarytree<int>*leftchild=new binarytree<int>(child);
            front->left=leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<endl<<"enter right chld of "<<front->data<<" : ";
        cin>>child;
        if(child!=-1)
        {
            binarytree<int>*rightchild=new binarytree<int>(child);
            front->right=rightchild;
            pendingnodes.push(rightchild);
        }
    }

    return root;

}

int countnodes(binarytree<int> *root)
{
    if(root==NULL)
        return 0;
    
    return 1 + countnodes(root->left) + countnodes(root->right);
}

void postoder(binarytree<int>*root)
{
    if(root==NULL)
        return;
    
    postoder(root->left);
    postoder(root->right);
    cout<<root->data<<" ";
}

void preoder(binarytree<int>*root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}

void inoder(binarytree<int>*root)
{
    if(root==NULL)
        return;
    
    inoder(root->left);
    cout<<root->data<<" ";
    inoder(root->right);
}

binarytree<int> * treebuilding(int *in, int *pre, int preS,int preE,int inS,int  inE)
{
    if(inS>inE)
    {
        return NULL;
    }
   
    int rootdata=pre[preS];
    binarytree<int>*root=new binarytree<int>(rootdata);

    int rootindex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(rootdata==in[i])
        {
            rootindex=i;
            break;
        }
    }


    int lpreS=preS+1;
    int linS = inS;
    int linE = rootindex-1;
    int lpreE = linE-linS+lpreS;
    int rpreS = lpreE +1;
    int rpreE = preE;
    int rinS = rootindex +1;
    int rinE = inE;


    root->left=treebuilding(in,pre,lpreS,lpreE,linS,linE);
    root->right=treebuilding(in,pre,rpreS,rpreE,rinS,rinE);

    return root;

    
}

binarytree<int> * buildtree(int *in,int *pre,int size)
{
    return treebuilding(in , pre , 0 , size -1 , 0 , size - 1);
}

int height(binarytree<int>*root)
{
    if(root==NULL)
        return 0;
    
    return 1+max(height(root->left),height(root->right));
}

pair<int,int> heightdiameter(binarytree<int>*root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftans=heightdiameter(root->left);
    pair<int,int> rightans=heightdiameter(root->right);

    int leftheight=leftans.first;
    int leftdiameter=leftans.second;
    int rightheight=rightans.first;
    int rightdiameter=rightans.second;

    int height=1 + max(leftheight,rightheight);
    int diameter = max(leftheight+rightheight,max(leftdiameter,rightdiameter));

    pair<int,int>p;
    p.first=height;
    p.second=diameter;
    return p;
}

int sumofallnodes(binarytree<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return root->data + sumofallnodes(root->left) + sumofallnodes(root->right);

}

int maxnode(binarytree<int>*root)
{
    if(root==NULL)
        return -1;
    
    int maximum=root->data;

    maximum=max(maximum,max(maxnode(root->left),maxnode(root->right)));
    return maximum;

}

bool findanode(binarytree<int>*root,int x)
{
    if(root==NULL)
        return false;
    
    if(root->data==x)
        return true;
    
    return findanode(root->left,x) || findanode(root->right,x);
}

pair<bool,int> balancedhelper(binarytree<int>*root)
{
    if(root==NULL)
    {
        pair<bool,int> p;
        p.first=true;
        p.second=0;
        return p;
    }
    
    pair<bool,int> leftans=balancedhelper(root->left);
    pair<bool,int> rightans=balancedhelper(root->right);

    int leftheight=leftans.second;
    int rightheight=rightans.second;

    if(abs(leftheight-rightheight)>1)
    {
        pair<bool,int> p;
        p.first=false;
        p.second=1+max(leftheight,rightheight);
        return p;
    }
    
    pair<bool,int>ans;
    ans.first=leftans.first && rightans.first;
    ans.second=1+max(leftans.second,rightans.second);

    return ans;
    
}

bool istreebalanced(binarytree<int>*root)
{
    pair<bool,int>ans=balancedhelper(root);
    return ans.first;
}

void leveloder(binarytree<int>*root)
{
    queue<binarytree<int>*> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);

    while(pendingnodes.size()!=0)
    {
        binarytree<int>*front=pendingnodes.front();
        pendingnodes.pop();
       
        if(pendingnodes.size()==0)
            break;

        if(front==NULL)
        {
            cout<<endl;
            pendingnodes.push(NULL);
        }        
        else
        {
            cout<<front->data<<" ";
            if(front->left)
                pendingnodes.push(front->left);
            
            if(front->right)
                pendingnodes.push(front->right);
        }
    }
}

binarytree<int>*removeleafnodes(binarytree<int>*root)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }

    root->left=removeleafnodes(root->left);
    root->right=removeleafnodes(root->right);

    return root;
}

vector<node*> levelwiselinkedlist(binarytree<int>*root)
{
    node *head=NULL;
    node *tail=NULL;
    vector<node*>output;
    queue<binarytree<int>*>pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);

    while(pendingnodes.size()!=0)
    {
        binarytree<int>*front=pendingnodes.front();
        pendingnodes.pop();

        if(pendingnodes.size()==0)
        {
            output.push_back(head);
            break;
        }

        if(front==NULL)
        {
            output.push_back(head);
            head=NULL;
            tail=NULL;
            pendingnodes.push(NULL);
        }
        else
        {
            node *p=new node;
            p->data=front->data;
            p->next=NULL;

            if(head==NULL)
            {
                head=tail=p;
            }
            else
            {
                tail->next=p;
                tail=p;
            }

            if(front->left)
            pendingnodes.push(front->left);

            if(front->right)
            pendingnodes.push(front->right);
            
        }
    }   

    return output;
}

void displaylinkedlist(node * p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void zigzagtree(binarytree<int>*root)
{
    stack<binarytree<int>*>s1;
    stack<binarytree<int>*>s2;

    s1.push(root);

    while(s1.size()!=0 || s2.size()!=0)
    {
        while(s1.size()!=0)
        {
            binarytree<int>*front=s1.top();
            s1.pop();
            cout<<front->data<<" ";
            if(front->left)
                s2.push(front->left);
            
            if(front->right)
                s2.push(front->right);
            
        }

        cout<<endl;

        while(s2.size()!=0)
        {
            binarytree<int>*front=s2.top();
            s2.pop();
            cout<<front->data<<" ";
            if(front->right)
                s1.push(front->right);
            
            if(front->left)
                s1.push(front->left);
        }

        cout<<endl;
    }



}

void nodeswithoutsiblings(binarytree<int>*root)
{
    stack<binarytree<int>*>s1;
    stack<binarytree<int>*>s2;

    s1.push(root);
    while(s1.size()!=0 || s2.size()!=0)
    {
        while(s1.size()!=0)
        {
            binarytree<int>*front=s1.top();
            s1.pop();
            if(front->left)
                s2.push(front->left);
            
            if(front->right)
                s2.push(front->right);
            
        }

        if(s2.size()==1)
        {
            cout<<s2.top()->data<<" ";
        }

        while(s2.size()!=0)
        {
            binarytree<int>*front=s2.top();
            s2.pop();
            if(front->left)
                s1.push(front->left);
            
            if(front->right)
                s1.push(front->right);
            
        }

        if(s1.size()==1)
        {
            cout<<s1.top()->data<<" ";
        }



    }

}

//////------------------PRACTICE QUESTIONS ON BINARY TREE ----------------------------------
binarytree<int>* create_insert_duplicate_nodes(binarytree<int>*root)
{
    if(root==NULL)
        return NULL;

    
    binarytree<int>*leftside=root->left;
    binarytree<int>*duplicatenode=new binarytree<int>(root->data);
    root->left=duplicatenode;
    
    duplicatenode->left= create_insert_duplicate_nodes(leftside);
    root->right = create_insert_duplicate_nodes(root->right);

    return root;

}

int pair_sum_binarytree(binarytree<int>*root,int x)
{
    //TODO pair sum binarytree
}


int main()
{
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    //8 5 10 2 6 -1 6 -1 -1 -1 7 -1 -1 -1 -1
    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
    // 1 2 3 4 5 -1 8 -1 -1 6 -1 -1 -1 -1 -1
    // int in[]={4,2,5,1,8,6,9,33,7};
    // int pre[]={1,2,4,5,33,6,8,9,7};
    // binarytree<int>*root=buildtree(in,pre,9);

    binarytree<int>*root=takeinputlevelwise();
    printlevelwise(root);
    cout<<endl;
    int a=pair_sum_binarytree(root,11);
 


    return 0;
}
