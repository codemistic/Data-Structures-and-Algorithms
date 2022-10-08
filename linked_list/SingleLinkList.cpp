#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int data){ 
        this -> data = data;
        this -> next = NULL;
    }

    ~node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memomry is free for node with data"<<value<<endl;
    }
};

void InsertAtHead(node* &head,int d){
    node* temp= new node(d);
    temp->next=head;
    head=temp;
}

void InsertAtTail(node* &Tail,int d){
    node* temp= new node(d);
    Tail->next=temp;
    Tail = Tail->next;
}

void InsertAtPosition(node* &Tail,node* &head, int position,int data){
    
    if(position==1){
        InsertAtHead(head,data);
        return;
    }
    else{
    node* temp=head;
    int cnt=1;
    while(cnt < position-1){
        temp = temp-> next;
        cnt++;
    }
    if(Tail->next == NULL){
        InsertAtTail(Tail,data);
    }
    node* nodetoinsert = new node(data);

    nodetoinsert->next =temp->next;
    temp->next= nodetoinsert;
    }
} 

void Deletenode(int position,node* &head){
    if(position ==1){
         node* temp = head;
         head =  head->next;
         temp->next =NULL;
         delete temp;
    }
    else{
        node* current = head;
        node* prev = NULL;

        int cnt =1;
        while(cnt < position){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current->next=NULL;
        delete current;
    }
}

void print(node* &head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp -> data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    
    node* node1 = new node(10);

    // cout<<node1 -> data<<endl;
    // cout<<node1 -> next<<endl;
    node*  head = node1;
    node*  Tail = node1;
    print(head);
    
    InsertAtTail(Tail,12);
    print(head);
    
    InsertAtTail(Tail,15);
    print(head);

    InsertAtPosition(Tail,head,1,5);
    print(head);
    
    return 0;
}