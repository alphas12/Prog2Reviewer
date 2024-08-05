#include <stdio.h>

void pointerArithmetic(int *arr, int size) {
    printf("Pointer Arithmetic:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(arr + i));  // Access elements using pointer arithmetic
    }
}

void dereferencingExample(int *ptr) {
    printf("\nDereferencing Pointer:\n");
    printf("Value pointed to by ptr: %d\n", *ptr);  // Dereference pointer to get the value
}

void manipulateArrayWithPointers(int *arr, int size) {
    printf("\nManipulating Array with Pointers:\n");
    for (int i = 0; i < size; i++) {
        *(arr + i) += 10;  // Add 10 to each element using pointer arithmetic
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int *ptr = arr;  // Pointer to the first element of the array
    
   int a = 10;
    int *p = &a;
    int **q = &p;
    int ***r = &q;

    printf("The value of a is %d", a);
    printf("The value of a is %d", *p);
    printf("The value of a is %d", **q);
    printf("The value of a is %d", ***r);
  
    printf("The address of a is %p %p", &a, p);
    printf("The addres of p is %p %p", &p, *q);
    printf("The addres of r is %p", r, &r);
    printf("The addres of q is %p", q, &q);


    pointerArithmetic(arr, size);
    dereferencingExample(ptr);
    manipulateArrayWithPointers(arr, size);
    pointerArithmetic(arr, size);  // Print the modified array

    return 0;
}
