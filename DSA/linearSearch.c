#include <stdio.h>
#include <stdlib.h>
#

#define MAX 20
typedef int itemType;

void fill(itemType a[], int n);
int search(itemType a[], int n, itemType x);
void show(itemType a[], int n);

int main()
{
    itemType list[MAX], x;
    int n, pos;

    printf("Enter the current size of the list: ");
    scanf("%d", &n);

    fill(list, n);
    show(list, n);

    printf("Enter the item to search: ");
    scanf("%d", &x);

    pos = search(list, n, x);

    if (pos == -1)
        printf("Item not found\n");
    else
        printf("Item %d found at index %d\n\n", list[pos], pos);

    return 0;
}

void fill(itemType a[], int n)
{
    int i;
    srand(time(0));
    for (i=0; i<n; ++i)
        a[i] = rand()%100;
}

int search(itemType a[], int n, itemType x)
{
    int i;
    for (i=0; i<n; ++i)
    {
        if (x==a[i]) //item found, success
            return i;
    }

    //if execution reaches here, item not found
    return -1; //failure

}
void show(itemType a[], int n)
{
    int i;
    printf("The list is: ");
    for (i=0; i<n; ++i)
        printf("%d  ", a[i]);
    printf("\n\n");
}
