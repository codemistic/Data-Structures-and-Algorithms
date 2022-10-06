#include <iostream>
using namespace std
class Node{
  public:
  int data;
  Node* next;

  Node(int i){
    this->data=i;
    this->next=NULL;
  }

};

Node* takeInput(){
  int data;
  cin>>data;
  Node* head=NULL;
  Node* tail=NULL;
  while(data!=-1){
    Node* newdata=new Node(data);
    if(head==NULL){
      head=newdata;
      tail=newdata;
    }
    else{
      tail->next=newdata;
      tail=newdata;
    }
    cin>>data;
  }
  return head;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
  return ;
}

int main(){
  Node* head = takeInput();
  print(head);
  return 0;
}
