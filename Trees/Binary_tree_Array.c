#include <stdio.h>


int complete_node = 15;

char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

// funtion to get parent
int get_parent(int index)
{
    if(tree[index]!='\0' && index>1 && index<=complete_node) //root has no parent
        return index/2;
    return -1;
}

int get_right_child(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree[index]!='\0' && ((2*index)+1)<=complete_node)
        return (2*index)+1;
    // right child doesn't exist
    return -1;
}

int get_left_child(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree[index]!='\0' && (2*index)<=complete_node)
        return 2*index;
    // left child doesn't exist
    return -1;
}

void preorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index]!='\0')
    {
        printf(" %c ",tree[index]); // visiting root
        preorder(get_left_child(index)); //visiting left subtree
        preorder(get_right_child(index)); //visiting right subtree
    }
}

void postorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index]!='\0')
    {
        postorder(get_left_child(index)); //visiting left subtree
        postorder(get_right_child(index)); //visiting right subtree
        printf(" %c ",tree[index]); //visiting root
    }
}

void inorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index]!='\0')
    {
        inorder(get_left_child(index)); //visiting left subtree
        printf(" %c ",tree[index]); //visiting root
        inorder(get_right_child(index)); // visiting right subtree
    }
}

int is_leaf(int index)
{
    // to check of the indices of the left and right children are valid or not
    if(!get_left_child(index) && !get_right_child(index))  
        return 1;
    // to check if both the children of the node are null or not
    if(tree[get_left_child(index)]=='\0' && tree[get_right_child(index)]=='\0')
        return 1;
    return 0; // node is not a leaf
}

int get_max(int a, int b)
{
    return (a>b) ? a : b;
}

int get_height(int index)
{
    // if the node is a leaf the the height will be 0
    // the height will be 0 also for the invalid cases
    if(tree[index]=='\0' || index<=0 || is_leaf(index))
        return 0;
    // height of node i is 1+ maximum among the height of left subtree and the height of right subtree
    return(get_max(get_height(get_left_child(index)), get_height(get_right_child(index)))+1);
}
