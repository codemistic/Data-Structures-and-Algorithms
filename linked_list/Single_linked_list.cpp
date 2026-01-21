#include <iostream>
using namespace std;
struct node // Structure of our node
{
    int data;
    node *link;
};
class linkedlist
{
    node *start; // Start pointer that points the first node

public:
    // If linkedlist is empty start will be NULL
    linkedlist()
    {
        start = NULL;
    }
    // Function that adds node at begining of out linked list
    void addatbeg(int num)
    {
        node *temp = new node;
        temp->data = num;
        temp->link = start;
        start = temp;
        cout << "Node added at begining "<< endl;
    }
    // Function that adds node at last
    void append(int num)
    {
        node *temp = new node;
        temp->data = num;
        // If linked list is empty make the node as the first node
        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            node *t = start;
            while (t->link != NULL)
            {
                t = t->link;
            }
            t->link = temp;
        }
        temp->link = NULL;
        cout << "Node appended "<< endl;
    }
    // Function that adds node at a specific location
    void addatloc(int loc, int num)
    {
        node *temp = new node;
        temp->data = num;
        node *t = start;
        for (int i = 1; i < loc; i++)
        {
            t = t->link;
            if (t == NULL)
            {
                cout << "There are less elements ! " << endl;
                return;
            }
        }
        temp->link = t->link;
        t->link = temp;
        cout << "Node added"<< endl;
    }
    // Function that deletes node
    void del(int num)
    {
        if (start == NULL)
        {
            cout << "Linked List is empty !" << endl;
        }
        else
        {
            node *t = start, *old;
            while (t->link != NULL)
            {
                if (t->data == num)
                {

                    if (t == start)
                    {
                        start = t->link;
                    }
                    else
                    {
                        old->link = t->link;
                    }
                    delete t;
                    cout<< "Node deleted"<< endl;
                    return;

                }
                else
                {
                    old = t;
                    t = t->link;
                }

            }
            cout << "Element not found !" << endl;
        }
    }
    // Function to diplay linked list
    void display()
    {
        if (start == NULL)
        {
            cout << "Linked List is empty" << endl;
        }
        else
        {
            cout << "Elements in Linked List are : ";
            node *t = start;
            while (t != NULL)
            {
                cout << t->data << " ";
                t = t->link;
            }
            cout << endl;
        }
    }
    // Function to count the number of node
    int count()
    {
        if (start == NULL)
        {
            cout << "Linked List is empty " << endl;
            return 0;
        }
        else
        {
            int counter = 0;
            node *t = start;
            while (t != NULL)
            {
                counter++;
                t = t->link;
            }
            return counter;
        }
    }
    ~linkedlist()
    {
        node *temp = start;
        while (start != NULL)
        {
            temp = start;
            start = start->link;
            delete temp;
        }
    }
};
int main()
{
    int ch, num, loc;
    linkedlist l;

    do
    {
        cout << " ====== SINGLY LINKED LIST ====== " << endl;
        cout << "Press 1 for add at begining " << endl;
        cout << "Press 2 for append" << endl;
        cout << "Press 3 for add at a locaton" << endl;
        cout << "Press 4 for deletion" << endl;
        cout << "Press 5 for display" << endl;
        cout << "Press 6 for counting nodes" << endl;
        cout << "Press 7 to exit" << endl;
        cout << "Enter your choice : ";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Enter number : ";
            cin >> num;
            l.addatbeg(num);
            break;
        case 2:
            cout << "Enter number : ";
            cin >> num;
            l.append(num);
            break;
        case 3:
            cout << "Enter location : ";
            cin >> loc;
            cout << "Enter number: ";
            cin >> num;
            l.addatloc(loc, num);
            break;
        case 4:
            cout << "Enter number: ";
            cin >> num;
            l.del(num);
            break;
        case 5:
            l.display();
            break;
        case 6:
             cout <<" Number of nodes are :" << l.count() << endl;
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice !!" << endl;
            break;
        }
    } while (1);
    return 0;
}
