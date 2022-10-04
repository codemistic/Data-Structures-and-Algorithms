struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};

tNode *rightMost(tNode* node, tNode *curr)
{
  while(node->right!=NULL and node->right!=curr)
    node=node->right;
  return node;
}

void MorrisTraversal(struct tNode* root)
{
  tNode *curr=root;
  while(curr!=NULL)
  {
    if(curr->left==NULL)
    {
      cout<<curr->data<<" ";
      curr=curr->right;
    }
    else
    {
      tNode *rm=rightMost(curr->left, curr);
      if(rm->right==NULL)
      {
        rm->right=curr;
        curr=curr->left;
      }
      else
      {
        rm->right=NULL;
        cout<<curr->data<<" ";
        curr=curr->right;
      }
    }
  }
}

