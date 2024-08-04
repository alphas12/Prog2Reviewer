
#include <stdio.h>
#include <stdlib.h>

int* divisibleby5(int * arr, int size) {
    int* newArray = (int*)calloc(sizeof(int) , (size + 1));  
    if(newArray == NULL){
        printf("Memory has not been allocated");
        return 0;
    }
    for (int i = 0, y = 1; i < size; i++) {
        if (*(arr + i) % 5 == 0) {
            newArray[y] = arr[i];
            y++;
            (*newArray)++;  
        }
    }

    return newArray;
}

int main() {
    int input_array[7] = {10, 7, 25, 15, 8, 20, 5};

    int* newArray = divisibleby5(input_array, 7);

    printf("Numbers divisible by 5: ");
    for (int i = 0; i <= newArray[0]; i++) {
        printf("%d ", newArray[i]);
    }

    printf("\nSum of numbers divisible by 5: %d\n", newArray[0]);

    
    free(newArray);

    return 0;
}
