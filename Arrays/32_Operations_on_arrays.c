// header files
#include <stdio.h>
#include <stdlib.h>

// global variables
int menuOption, process = 0;

// array and its properties
struct array
{
    int counter;
    int array1[10];
} a1;

// setting value of variables inside the struct
void setValues()
{
    a1.counter = 0;
}

// main menu
int menu()
{
    printf("Press 1 for insertion\n");
    printf("Press 2 for deletion\n");
    printf("Press 3 for traversing\n");
    printf("Press 4 for linear search\n");
    printf("Press 5 for selection sort\n");
    printf("Press 9 to exit\n");
    scanf("%d", &menuOption);
}

int menu1()
{
    printf("Press 1 for insertion\n");
    printf("Press 9 to exit\n");
    scanf("%d", &menuOption);
}

// operation functions
void printArr()
{
    if (a1.counter == 0)
    {
        printf("The array is empty\n");
    }
    else
    {
        printf("The array is : ");
        for (int i = 0; i < a1.counter - 1; i++)
        {
            printf("%d, ", a1.array1[i]);
        }
        printf("%d\n", a1.array1[a1.counter - 1]);
    }
    printf("\n");
}

int insertion()
{
    int element, index, choice;
    int beginning()
    {
        printf("Enter element to insert at the beginnning\n");
        scanf("%d", &element);
        if (a1.counter>0)
        {
            for (int i = a1.counter; i >=0 ; i--)
            {
                a1.array1[i] = a1.array1[i-1];
            }
        }
        a1.array1[0] = element;
        a1.counter++;
        printArr();
    }
    int atIndex()
    {
        printf("Enter the index: ");
        scanf("%d", &index);
        if (index<=a1.counter)
        {    
            printf("Enter element to insert at the index:%d\n", index);
            scanf("%d", &element);
            
            for (int i = a1.counter; i > index; i--)
            {
                a1.array1[i] = a1.array1[i-1];
            }
            a1.array1[index] = element;
            a1.counter++;
            printArr();
        }
        // checks
        else
        {
            printf("Please enter correct index");
        }
        
    }
    int end()
    {
        printf("Enter element to insert at the end\n");
        scanf("%d", &element);
        a1.array1[a1.counter] = element;
        a1.counter++;
        printArr();
    }
insertOneCheckpoint:
    switch (a1.counter)
    {
    case 0:
        beginning();
        break;

    case 2 ... 9:
        printf("Enter 1 to enter in the beginning\n");
        printf("Enter 2 to enter in the end\n");
        printf("Enter 3 to enter at a specific index\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            beginning();
        }
        else if (choice == 2)
        {
            end();
        }
        else if (choice == 3)
        {
            atIndex();
        }
        else
        {
            printf("Choice out of range\n");
            goto insertOneCheckpoint;
        }
        break;
    default:
        printf("Index out of bounds\n");
        break;

    case 1:
        printf("Enter 1 to enter in the beginning\n");
        printf("Enter 2 to enter in the end\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            beginning();
        }
        else if (choice == 2)
        {
            end();
        }
        else
        {
            printf("Choice out of range\n");
            goto insertOneCheckpoint;
        }
        break;
    }
}

int deletion()
{
    int index;
insertDeleteCheckpoint:
    printf("Enter the index of the element you want to delete\n");
    scanf("%d", &index);
    if (index >= 0 && index <= a1.counter)
    {
        for (int i = index; i <= a1.counter; i++)
        {
            a1.array1[i] = a1.array1[i + 1];
        }
        a1.counter--;
        printArr();
    }
    else
    {
        printf("Index out of range\n");
        goto insertDeleteCheckpoint;
    }
}

int traversing()
{
    int index;
insertTraverseCheckpoint:
    printf("Enter the index of the element\n");
    scanf("%d", &index);
    if (index >= 0 && index <= a1.counter)
    {
        printf("%d", a1.array1[index]);
    }
    else
    {
        printf("Index out of range");
        goto insertTraverseCheckpoint;
    }
    printArr();
}

int traversing2(){
    for (int i = 0; i < a1.counter; i++)
    {
        printf("%d\n",i);
    }
    printArr();
}

int searching()
{
    int element, crash = -1;
insertSearchingCheckpoint:
    printf("Enter the element you want to search for: \n");
    scanf("%d", &element);
    for (int i = 0; i < a1.counter; i++)
    {
        if (a1.array1[i] == element)
        {
            crash = i;
        }
    }
    if (crash >= 0)
    {
        printf("The index of %d is %d\n", element, crash);
    }
    else
    {
        printf("No element found\n");
        goto insertSearchingCheckpoint;
    }
}

int sorting()
{
    int min, crash, temp;
    for (int i = 0; i < a1.counter; i++)
    {
        min = a1.array1[i];
        for (int j = i + 1; j < a1.counter; j++)
        {
            if (a1.array1[j] < min)
            {
                min = a1.array1[j];
                crash = j;
            }
        }
        temp = a1.array1[i];
        a1.array1[i] = min;
        a1.array1[crash] = temp;
    }
    printArr();
}

// main function
int main()
{
    setValues();
    printArr();
showMenu:
    if (a1.counter == 0)
    {
        menu1();
        switch (menuOption)
        {
        case 1:
            insertion();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter correct input\n");
            goto showMenu;
            break;
        }
    }

    else
    {
        menu();
        switch (menuOption)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traversing2();
            break;
        case 4:
            searching();
            break;
        case 5:
            sorting();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter correct input\n");
            goto showMenu;
            break;
        }
    }

    // making sure our menu runs inside a loop
    goto showMenu;
    return 0;
}