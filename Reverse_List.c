#include <stdio.h>
#include <stdlib.h>
List *reverseList(List *lp);

typedef int itemType;

//self referential structure
typedef struct node
{
    itemType info;
    struct node *link;
}node;

typedef struct List
{
    node *head, *tail;
}List;

node *createNode(itemType x)
{
    node *p;
    p = (node *)malloc(1*sizeof(node));
    if (p==NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    p->info = x;
    p->link = NULL;
    return p;
}
void show(List *lp)
{
    node *p;

    p = lp->head;
    printf("Linked list is: ");
    while(p != NULL)
    {
        printf("%d---->", p->info);
        p = p->link;
    }
    printf("NULL\n\n");
}

void insertAtTail(List *lp, itemType x)
{
    node *p;

    p = createNode(x);

    if (lp->head == NULL)
        lp->head = p;
    else
        lp->tail->link = p;

    lp->tail = p;
}

void initialize(List *lp)
{
    lp->head = NULL;
    lp->tail = NULL;
}
List *createList()
{
    List *lp;
    itemType x;
    int n, i;

    //allocate space for head and tail
    lp = (List *)malloc(sizeof(List));
    if (lp==NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    initialize(lp);

    printf("Enter count of items: ");
    scanf("%d", &n);

    srand(time(0));
    for (i=0; i<n; ++i)
    {
        x = rand()%100;
        insertAtTail(lp, x);
    }
    return lp;
}
List *reverseList(List *lp)
{
    node *p, *q, *r, *temp;

    p = lp->head;
    q = p->link;
    r = q->link;

    while(q != NULL)
    {
        q->link = p;
        p = q;
        q = r;
        if (r!=NULL)
            r = r->link;
    }

    //swap head and tail
    temp = lp->head;
    lp->head = lp->tail;
    lp->tail = temp;

    //make NULL of link of new tail
    lp->tail->link = NULL;
}

int main()
{
    List *lp;

    lp = createList();
    show(lp);
    reverseList(lp);
    show(lp);
    return 0;
}
