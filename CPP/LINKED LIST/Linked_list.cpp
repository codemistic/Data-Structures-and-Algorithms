#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;
// initialised first as null

void createList(int arr[], int n)
{
    struct Node *t;
    struct Node *last;

    // setup a new node
    first = new struct Node;
    first->data = arr[0];
    first->next = NULL;

    // last is first as 1 element only
    last = first;

    for (int i = 1; i < n; i++)
    {
        // setup a new node
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;

        // make current last point to new node
        last->next = t;

        // update last
        last = t;
    }
};

void printList(struct Node *p)
{
    // while address of next block is not null
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->next;
    }

    cout << endl;
}

// time : O(n)
// space : O(1)
int countNodes(struct Node *p)
{
    // while address of next block is not null
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

void insert(struct Node *p, int index, int data)
{
    // new node in heap
    struct Node *newNode;
    newNode = new struct Node;
    newNode->data = data;

    if (index == 0)
    {
        // linking
        newNode->next = first;
        first = newNode;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        newNode->next = p->next;
        p->next = newNode;
    }

}

void deleteList(struct Node *p , int index)
{
    struct Node *prev;

    if(index == 0){

        // pointing to 1st node
        prev = first;
        
        // pointing to 2nd node
        first = first->next;

        delete prev;
    }

    else{

        for (int i = 0; i < index-1; i++)
        {
            prev = p;
            p = p->next;
        }

        prev->next = p->next;
        delete p;
        
    }
}

struct Node *searchList(struct Node *p, int target)
{
    while (p != 0)
    {
        if (p->data == target)
        {
            // returns address of that node which have data == target
            return p;
        }
        p = p->next;
    }

    return NULL;
}



int main()
{

}