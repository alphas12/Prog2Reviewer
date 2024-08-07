 #include <stdio.h>
#include <stdlib.h>


int * listNum(int *A, int size, int max){

    int *newArr = (int*) malloc ((max + 1) * sizeof(int));

    int i, j = 0, k = 1;

    for(i = 0; i < size; i++, k++){
        if(*(A + i) == k){
                newArr[j] = *(A + i);
                j++;
        } else {
                newArr[j] = k;
                j++;
                i--;
        }
    }

    newArr[j] = -1;
    size = j;  // Update the size of the new array
    return newArr;

}




int main() {
    int numElements = 6;
    int arr[6] = {1, 3, 5, 6, 7, 8};
    int max = 8;

    int *newArr = listNum(arr, numElements, max);

    int i;
    for (i = 0; newArr[i] != -1; i++) {
        printf("%d ", newArr[i]);
    }

    free(newArr);  // Free the allocated memory

    return 0;
}