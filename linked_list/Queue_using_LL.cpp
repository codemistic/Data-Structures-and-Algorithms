#include<bits/stdc++.h>

using namespace std;


struct QNode{
    int data;
    QNode *next;
    
    QNode(int n){
        data = n;
        next = NULL;
    }
};

struct Queue{
    
    QNode *front,*rear;
    
    Queue(){
        front = rear = NULL;
    }
    void enQueue(int x){
        QNode* temp = new QNode(x);
        if(rear == NULL){ 
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void deQueue(){
        QNode* temp;
        if(front == NULL){
            return ;
        }

        int x = front->data;
        temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete (temp);
    }

    void print(){
        //QNode* temp = front;
        while(front!=NULL){
            cout<<front->data<<" ";
            front=front->next;
        }
    }
};
int main(){
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    //q.deQueue();
    //q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    //q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data<<endl;
    q.print();
    return 0;
}