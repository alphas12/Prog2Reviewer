#include <stdio.h>

typedef struct {
    char fname[24];
    char MI;
    char lname[16];
    int age;
    char gender;
} infoinp;

infoinp student() {
    infoinp newStudent;  // Declare a local variable of type infoinp

    printf("Enter your first name: ");
    gets(newStudent.fname);

    printf("Enter your Middle Initial: ");
    scanf(" %c", &newStudent.MI);  // Use & to get the address of MI

    printf("Enter your Lastname: ");
    scanf("%s", newStudent.lname);

    printf("Enter your age: ");
    scanf("%d", &newStudent.age);

    printf("Enter your gender (M or F): ");
    scanf(" %c", &newStudent.gender);

    return newStudent;  // Return the initialized instance of infoinp
}

void display(infoinp stud) {

    puts("\n-------------------DETAILS -------------------\n");
    printf("%s %c %s \n%d years old", stud.fname, stud.MI, stud.lname, stud.age);

    if (stud.gender == 'M' || stud.gender == 'm') {
        printf("\nGender: Male\n");
    } else {
        printf("\nGender: Female\n");
    }
}

int main() {
    infoinp student1 = student(); 

    display(student1);

    return 0;
}
