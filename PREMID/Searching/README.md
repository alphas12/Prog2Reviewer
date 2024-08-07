# Types of Searching Algorithm

## Linear Search

Linear Search is the simplest searching algorithm. It works by iterating through each element in the array (or list) sequentially until the `desired element is foundor the end of the array is reached`.

#### Characteristics:

- **Time Complexity:**  
    - O(n), where n is the number of elements in the array.
    - Best for small or unsorted arrays.
    - No preconditions for the array (it can be sorted or unsorted).

```c

#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    int i; 
    for (i = 0; i < n && arr[i] != x; i++) {}
    if(arr[i] == x) ? i : 0;
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    int result = linearSearch(arr, n, x);
    if (result == 0) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}

```

# Binary Search

Binary Search is a more efficient searching algorithm that works on sorted arrays. It divides the array into halves to reduce the search interval by half each time. Binary Search repeatedly `compares the middle element with the target value` and `eliminates half of the array until the target value is found or the array is exhausted`.

### Characteristics:

- Time Complexity:
    -  O(log n), where n is the number of elements in the array.
    - Best for large, sorted arrays.
    - Requires the array to be sorted beforehand.

```c
    #include <stdio.h>

int binarySearch(int arr[], int size, int x ) {
    int low = 0, 
    int high = size - 1;
    int mid = 0;

    while(low <= high && arr[mid] != x){
        mid = (low + high) / 2;
        if(arr[mid] < x){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (low < hi) ? i : 0;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, n , x);
    if (result == 0) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}
```