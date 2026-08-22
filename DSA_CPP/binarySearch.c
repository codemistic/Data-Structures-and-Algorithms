#include <stdio.h>
#include <stdlib.h>
#

#define MAX 20
typedef int itemType;


int search(itemType a[], int n, itemType x);
void show(itemType a[], int n);

int main()
{
    itemType list[MAX]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    itemType x;
    int n=10, pos;

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

int search(itemType a[], int n, itemType x)
{
    int low, high, mid, count;
    low = 0;
    high = n-1;
    count = 0;


    while (low<high)
    {
        mid = (low+high)/2;
        ++count;
        if (x == a[mid]) //success
        {
            printf("Count of comp is: %d\n", count);
            return mid;
        }

        else if (x < a[mid])
            high = mid-1;
        else //x > a[mid]
            low = mid+1;
    }
    printf("Count of comp is: %d\n", count);

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
