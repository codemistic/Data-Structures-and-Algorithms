#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int height;
    T data;
};

Node<int> *root = NULL;

template <typename T>
int nodeHeight(Node<T> *p){
    int hl, hr;
    hl = p && p -> lchild ? p -> lchild -> height : 0;
    hr = p && p -> rchild ? p -> rchild -> height : 0;

    return max(hl + 1, hr + 1);
}


template <typename T>
int balanceFactor(Node<T> *p){
    int hl, hr;
    hl = p && p -> lchild ? p -> lchild -> height : 0;
    hr = p && p -> rchild ? p -> rchild -> height : 0;

    return hl - hr;
}

template <typename T>
Node<T>* LLRotation(Node<T>* p){
    Node<T> *pl, *plr;
    pl = p -> lchild;
    plr = pl -> rchild;

    pl -> rchild = p;
    p -> lchild = plr;
    p -> height = nodeHeight(p);
    pl -> height = nodeHeight(pl);
    // plr's height remains same;

    if(root == p)
        root = pl;

    return pl;
}

template <typename T>
Node<T>* RRRotation(Node<T>* p){
    return NULL;
}

template <typename T>
Node<T>* LRRotation(Node<T>* p){
    return NULL;
}

template <typename T>
Node<T>* RLRotation(Node<T>* p){
    return NULL;
}


template <typename T>
Node<T>* insert_bst_recursive(Node<T>* p, T key){
        Node<T>* t;
        if(p == NULL){
            t = new Node<T>;
            t -> data = key;
            t -> height = 1;
            t -> lchild = NULL;
            t -> rchild = NULL;
            return t;
        }
        if(key < p -> data)
            p -> lchild = insert_bst_recursive(p -> lchild, key);
        else if(key > p -> data)
            p -> rchild = insert_bst_recursive(p -> rchild, key);

        p -> height = nodeHeight(p);

        if(balanceFactor(p) == 2 && balanceFactor(p -> lchild) == 1)
            return LLRotation(p);
        else if(balanceFactor(p) == 2 && balanceFactor(p -> rchild) == -1)
            return LRRotation(p);
        else if(balanceFactor(p) == -2 && balanceFactor(p -> lchild) == -1)
            return RRRotation(p);
        else if(balanceFactor(p) == -2 && balanceFactor(p -> lchild) == 1)
            return RLRotation(p);


        return p;
}

int main(){
    fastIO;

    root = insert_bst_recursive(root, 10);
    // cout << root -> data;
    insert_bst_recursive(root, 5);
    insert_bst_recursive(root, 2);

    cout << root -> data;

    return 0;
}