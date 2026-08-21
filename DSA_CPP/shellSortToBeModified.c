#include <stdio.h>
#include <stdlib.h>

#define MAX 20
typedef int itemType;

void fill(itemType L[], int n);
void show(itemType L[], int n);
void shellSort(itemType L[], int n);

int main()
{
    itemType list[MAX];
    int n;

    printf("Enter the current size of the list: ");
    scanf("%d", &n);

    fill(list, n);
    show(list, n);
    shellSort(list, n);
    show(list, n);

    return 0;
}

void shellSort(itemType L[], int n)
{
    int i, current, h;
    itemType temp;

    for(h=n/3+1; h>=1; h=h/3+1)
    {
        for (current=h; current<n; current+=h)
        {
            temp = L[current];
            for (i=current-h; i>=0; i-=h)
            {
                if (L[i]>temp)
                {
                    L[i+h] = L[i];
                    //show(L,n);
                    //getch();
                }
                else
                    break;
            }
            L[i+h] = temp;
        }
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
