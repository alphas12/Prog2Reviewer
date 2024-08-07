# Elementary Sorting Algorithm

## Bubble Sort 

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, `compares adjacent elements`, and `swaps them if they are in the wrong order`. The pass through the list is repeated until the list is sorted. It gets its name because smaller elements "bubble" to the top of the list (or larger elements "sink" to the bottom) with each pass.

```c
void bubbleSort(int arr[], int size){

    int i, j, temp;

    for(i = 0, i <  size - 1, i++){
        for(j = 0, j < size - i - 1, j++){
            if(arr[j] > arr[j + 1]){
                temp = a[j];
                a[j] = a[j+ 1];
                a[j + 1] = temp;
            }
        }
    }
}
```

**Challenge: Try to visualize on your own for Bubble Sort!**

## Insertion Sort

Insertion Sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

```c
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

**Challenge: Try to visualize on your own for Insertion Sort!**

## Selection  Sort

Repeatedly selects the minimum element from the unsorted portion and swaps it with the first unsorted element.

```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

**Challenge: Try to visualize on your own for Selection Sort!**
