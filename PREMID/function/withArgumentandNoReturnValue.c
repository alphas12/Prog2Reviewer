#include <stdio.h>

void aveEven (int arr[], int val){
  
    int sum = 0, count = 0;
    for(int i = 0; i < val; i++){
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
        if(arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }

    printf("List {");
    int j, comma = 1;

    for(j = 0; j < val; j++){
        if(comma == 0){
            printf(", ");
        }
        printf("%d", arr[j]);
        comma = 0;
    }
    printf("}\n");
    
    printf("The sum of even is %d.", sum);

    float ave = (float)sum/(float)count;
    printf("\nThe average of even is %.2f.", ave);

    return 0;
}

int main(){

    int val;

    printf("Enter how many values: ");
    scanf("%d", &val);

    int arr[val];

    aveEven(arr, val);
   
    return 0;
}
