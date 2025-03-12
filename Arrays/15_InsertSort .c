// #include<stdio.h>

// struct Array 
// {
// 	int A[20];
// 	int length;
// 	int size;
// };
// void Display (struct Array arr)
// {
// 	int i;
// 	for (i=0;i<arr.length;i++)
// 	printf("%d ",arr.A[i]);
	
// }

// void InsertSort(struct Array *arr,int x)
// {
// 	int i=arr->length-1;
// 	if (arr->length==arr->size) return ;
// 	while (i>=0 && arr->A[i]>x)
// 	{
// 		arr->A[i+1]=arr->A[i];
// 		i--;
//     }
      
	
	
//   arr->A[i+1]=x;

// 	arr->length++;
	
// }


// int main()

// {
// 	struct Array arr={{2,3,5,10,15},5,20};
// 	InsertSort(&arr,1);
// 	Display(arr);
// 	return 0;
// }

#include <stdio.h>

struct Array {
    int A[20];
    int length;
    int size;
};

// Function to display array elements
void Display(struct Array arr) {
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

// Function to insert an element in a sorted array
void InsertSort(struct Array* arr, int x) {
    if (arr->length == arr->size) 
        return;  // Prevent inserting if array is full

    int i = arr->length - 1;

    // Shift elements to the right until we find the correct position
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    // Insert x at the correct position
    arr->A[i + 1] = x;
    arr->length++;
}

int main() {
    struct Array arr = {{2, 3, 5, 10, 15}, 5, 20};  // Predefined sorted array

    printf("Original Array: ");
    Display(arr);

    InsertSort(&arr, 1);  // Insert value into sorted array

    printf("After Insertion: ");
    Display(arr);

    return 0;
}
