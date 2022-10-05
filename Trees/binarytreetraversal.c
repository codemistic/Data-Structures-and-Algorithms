 #include <stdio.h>
  #include <stdlib.h>

  struct tnode {
        int data;
        struct tnode *left, *right;
  };

  struct tnode *root = NULL;


  struct tnode * createNode(int data) {
        struct tnode *newNode;
        newNode  = (struct tnode *) malloc(sizeof(struct tnode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return (newNode);
  }


  void insertion(struct tnode **node, int data) {
        if (!*node) {
                *node = createNode(data);
        } else if (data < (*node)->data) {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) {
                insertion(&(*node)->right, data);
        }
  }
  void postOrder(struct tnode *node) {
        if (node) {
                postOrder(node->left);
                postOrder(node->right);
                printf("%d  ", node->data);
        }
        return;
  }


  void preOrder(struct tnode *node) {
        if (node) {
                printf("%d  ", node->data);
                preOrder(node->left);
                preOrder(node->right);
        }
        return;
  }


  void inOrder(struct tnode *node) {
        if (node) {
                inOrder(node->left);
                printf("%d  ", node->data);
                inOrder(node->right);
        }
        return;
  }

  int main() {
        int data, ch;
        while (1) {
                printf("\n1. Insertion\n2. Pre-order\n");
                printf("3. Post-order\n4. In-order\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter ur data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                break;
                        case 2:
                                preOrder(root);
                                break;
                        case 3:
                                postOrder(root);
                                break;
                        case 4:
                                inOrder(root);
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf(" wrong option\n");
                                break;
                }
        }
        return 0;
  }