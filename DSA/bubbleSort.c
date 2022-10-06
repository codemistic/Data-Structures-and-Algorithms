#include <stdio.h>
#include <stdlib.h>

#define MAX 20
typedef int itemType;

void fill(itemType L[], int n);
void show(itemType L[], int n);
void bubbleSort(itemType L[], int n);

int main()
{
    itemType list[MAX];
    int n;

    printf("Enter the current size of the list: ");
    scanf("%d", &n);

    fill(list, n);
    show(list, n);
    bubbleSort(list, n);
    show(list, n);

    return 0;
}

void bubbleSort(itemType L[], int n)
{
    int current, i, pass;
    itemType temp;

    current = n-1;
    for (pass=0; pass<n-1; ++pass)
    {
        for (i=0; i<current; ++i)
        {
            if (L[i]>L[i+1])
            {
                //swap
                temp = L[i];
                L[i] = L[i+1];
                L[i+1] = temp;
            }
            show(L, n);
            getch();
        }
        --current;
        printf("\n\n\n");
    }
}

void fill(itemType L[], int n)
{
    int i;
    srand(time(0));
    for (i=0; i<n; ++i)
        L[i] = rand()%100;
}
void show(itemType L[], int n)
{
    int i;
    printf("The list is: ");
    for (i=0; i<n; ++i)
        printf("%d  ", L[i]);
    printf("\n\n");
}
