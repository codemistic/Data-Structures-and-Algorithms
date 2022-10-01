//DS LAB Assignment-4 Maintaining Sorted Array by Aayush Patel 2K20/CO/11
#include <stdio.h>
void insert(int *a, int x, int n)
{
    int i;
    for (i = n - 1; (a[i] > x) && i >= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[i + 1] = x;
}
int deleteelement(int *a, int index, int n)
{
    if (index >= n)
        return -1;
    for (int i = index; i < n - 1; i++)
        a[i] = a[i + 1];
    return 1;
}
int search(int *a, int k, int n)
{
    int l = 0,h = n;
    while (l <= h)
    {
        int m =l+(h-l)/2;
        if (a[m] == k)
            return m;
        else if (k > a[m])
            l = m + 1;
        else if (k < a[m])
            h = m - 1;
    }
    return -1;
}

void display(int *a, int n)
{
    printf("Displaying Sorted Array List :\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int op, n = 0;
    int a[30];
    do
    {
        printf("\nOperations Menu Options:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        int x;
        printf("Enter your op:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter element to be inserted:");
            scanf("%d", &x);
            insert(a, x, n);
            n++;
            printf("Element inserted.\n");
            break;
        case 2:
            printf("Enter element's index to be deleted:");
            scanf("%d", &x);
            if (deleteelement(a, x, n) == -1)
                printf("Invalid Index\n");
            else
            {
                printf("Element Deleted.\n");
                n--;
            }
            break;
        case 3:
            printf("Enter element to be searched:");
            scanf("%d", &x);
            if (search(a, x, n) == -1)
                printf("Element Not Found\n");
            else
                printf("Element found at %dth position\n", search(a, x, n));
            break;
        case 4:
            display(a, n);
            break;
        default:
            printf("Exit!");
            break;
        }
    } while (op != 5);
    return 0;
}
