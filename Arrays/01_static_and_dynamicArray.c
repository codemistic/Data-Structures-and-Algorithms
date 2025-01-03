#include <stdio.h>
#include <stdlib.h>

// Define a constant for array size
#define ARRAY_SIZE 5

int main()
{
    // Static array allocated on the stack
    int A[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    int* p; // Pointer for dynamically allocated array
    int i;

    // Dynamically create an array on the heap
    p = (int*)malloc(ARRAY_SIZE * sizeof(int));
    if (p == NULL) // Check if malloc was successful
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit with error code
    }

    // Initialize the dynamically allocated array
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        p[i] = i + 1; // Assign values (same as static array)
    }

    // Iterate and print the static array
    printf("Static array elements:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Iterate and print the dynamic array
    printf("Dynamic array elements:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(p);

    return 0;
}
