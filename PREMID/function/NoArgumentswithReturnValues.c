#include <stdio.h>

int getNumber() {
    return 42;
}

int main() {
    int number = getNumber(); // Function call
    printf("The number is: %d\n", number);
    return 0;
}
