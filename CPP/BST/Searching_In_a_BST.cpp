#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
  int data;
  struct node *left, *right;
};

// Create a node
struct node *createnode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}
 	
   

int search(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           
           return 1;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   return 0;
}
struct node *insert(struct node *node, int key) {
	if(search(node,key)==1){
		printf("Cannot insert %d, already in BST", key);
	}
	else{
	
	 	if (node == NULL){
	  		 return createnode(key);
		}
	  	if (key < node->data){
	    	node->left = insert(node->left, key);
		}
	  	else{
	    	node->right = insert(node->right, key);
		}
	}
	
  return node;
}


int main() {
  struct node *root = NULL;
  int ch;
    int x;
    cout<<"Press 0 to exit else enter 1: ";
    cin>>ch;
    while(ch!=0)
    {
        cout<<"\n"<<"1.Insertion"<<"\n"<<"2.View"<<"\n"<<"3.search"<<"\n";
        cout<<"\n"<<"Enter choice :";
        cin>>ch;
        switch (ch)
        {
        case 1:
        	cout<<"Enter the value you want to insert in binary search tree: ";
        	cin>>x;
            root = insert(root, x);
            break;
        case 2:
            cout << "Inorder traversal: ";
 		  	 inorder(root);
            break;
        case 3:
            cout<<"The element you want to search: ";
        	cin>>x;
 		  	 if(search(root,x)==1){
				cout<<"\n"<<x<<"  is present in BST";
			}
			else{
				cout<<"\n"<<x<<"  is not found";
			
			}
			
            break;
      
        default:
            printf("\nINVALID CHOICE !!");
            break;
        }
    }
return 0;


}
