#include<bits/stdc++.h>
using namespace std;

class Tree {
    public:
    int data;
    int hd;
    Tree *left;
    Tree *right;

};

Tree* newNode(int data){
    Tree *new_node = new Tree();
    new_node->data = data;
    new_node->hd = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;

}

void setHorizontalDistance(Tree* root, int hd){

    if(root == NULL)return;

  root->hd = hd;
  setHorizontalDistance(root->left, hd-1);
  setHorizontalDistance(root->right, hd +1); 
}
void bottomView(Tree *root, map<int, pair<int,int>>&m, int d){
if(root == NULL)return;
if(m[root->hd].first < d){
m[root->hd].first = d;
m[root->hd].second = root->data;
}
if(root->left)
bottomView(root->left, m, d+1 );

if(root->right)
bottomView(root->right, m, d+1);
}

int main(){
   
   Tree *root =  newNode(20);
    root->left =  newNode(8);
    root->right =  newNode(22);
    root->left->left =  newNode(5);
    root->left->right =  newNode(3);
    root->right->left =  newNode(4);
    root->right->right =  newNode(25);
    root->left->right->left =  newNode(10);
    root->left->right->right =  newNode(14);

    setHorizontalDistance(root, 0);

    map<int, pair<int, int>>m;
    bottomView(root, m, 1);

    for(auto x: m){
        cout<<x.second.second<<" ";
    }



    return 0;
}