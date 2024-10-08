
#include<bits/stdc++.h>
using namespace std;
struct Queue{
    stack<int> s1,s2;


    void enqueue(int x){
       
            s1.push(x);
        
    }
    int dequeue(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
            
        }
        return ans;
        
    }
    
    
};
int main(){
    Queue q;
    int ch;
    int x;
    cout<<"Press 0 to exit else enter 1: ";
    cin>>ch;
    while(ch!=0)
    {
        cout<<"\n"<<"1.ENQUEUE"<<"\n"<<"2.DEQUQUE"<<"\n";
        cout<<"\n"<<"Enter choice :";
        cin>>ch;
        switch (ch)
        {
        case 1:
        	cout<<"Enter the value you want to enqueue: ";
        	cin>>x;
            q.enqueue(x);
            break;
        case 2:
            cout<<"Dequeued element is : "<<q.dequeue()<<"\n";
            break;
      
        default:
            printf("\nINVALID CHOICE !!");
            break;
        }
    }
    
  
    return 0;
}
