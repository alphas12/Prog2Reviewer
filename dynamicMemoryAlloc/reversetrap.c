#include <stdio.h>
#include <stdlib.h>

int * revArray(int arr[], int val){

    int *newArr = (int*)malloc((val + 1) * sizeof(int));
    int k, l = 0;

    for(k = val - 1; k >= 0; k--){
          newArr[l] = arr[k];
          l++;
    }
    newArr[l] = -1;
    return newArr;
}

int main(){

    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);


    int arr[size];

     for(int i = 0; i <  size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        if(arr[i] < 0){
            i--;
        }
    }

    printf("Original array: [");
    int j, comma = 1;
    for(j = 0; j < size; j++){
        if(comma == 0){
            printf(", ");
        }
        printf("%d", arr[j]);
        comma = 0;
    }
    printf("]\n");

    int *newArr = revArray(arr, size);

    printf("Reverse array: [");
    
    int a;
    for(a = 0; newArr[a] != -1; a++){
        if(comma == 1 ){
            printf(", ");
        }
        printf("%d", newArr[a]);
        comma = 1;
    }

    printf("]");

    free(newArr);
 
    return 0;
}