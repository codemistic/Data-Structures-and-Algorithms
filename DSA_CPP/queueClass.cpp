#include <iostream>

using namespace std;

typedef int itemType;

class Queue
{
private:
    int front, rear, count, max;
    itemType *a;

public:
    Queue(int s=5)
    {
        initialize();
        max = s;
        a = new itemType[max];
    }
    initialize()
    {
        front = 0;
        rear = -1;
        count = 0;
    }
    int full()
    {return count==max;}
    int empty()
    {return count==0;}

    void addition(itemType x)
    {
        if (full())
        {
            cout<<"Queue overflow\n";
            exit(1);
        }
        rear = (rear+1)%max;
        a[rear] = x;
        ++count;
    }

    itemType deletion()
    {
        if (empty())
        {
            cout<<"Queue underflow\n";
            exit(2);
        }
        itemType x;
        x = a[front];
        front = (front+1)%max;
        --count;
        return x;
    }
    void show()
    {}

    //free the memory allocated in the constructor
    ~Queue()
    {delete a;}
};

int main()
{
    Queue q(4);
    itemType x;

    x=10; q.addition(x);
    x=50; q.addition(x);
    x=90; q.addition(x);
    x=20; q.addition(x);
    //x=10; q.addition(x);  //overflow

    while (!q.empty())
        cout<<"The deleted item is: "<<q.deletion()<<endl;

    //x = q.deletion(); //underflow
    return 0;
}
