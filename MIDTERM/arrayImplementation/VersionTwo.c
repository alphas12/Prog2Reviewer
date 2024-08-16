#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for memmove
#define SIZE 10

typedef struct {
    char name[20];
    unsigned int ID;
    char position[20];
    float salary;
    int hours;
} Employee;

typedef struct {
    Employee employeetype[SIZE];
    int count;
} *EmployeeRecordtype; ///This is VERSION TWO

EmployeeRecordtype initList();
Employee add_employee();

void delete_employee(EmployeeRecordtype A, unsigned int x) {
    int i, pos, y;
    for (i = 0; i < A->count && x != A->employeetype[i].ID; i++);

    if (i < A->count) {
        pos = i;
        for (y = pos + 1; y < A->count; y++) {
            memmove(&A->employeetype[y - 1], &A->employeetype[y], sizeof(Employee));
        }
        (A->count)--;
        printf("\nEmployee deleted\n");
    }
    else {
        printf("\nEmployee with ID %u not found\n", x);
    }
}

void search_employee(EmployeeRecordtype S, unsigned int A) {
    int i;
    for (i = 0; i < S->count && A != S->employeetype[i].ID; i++);

    if (i < S->count) {
        printf("Employee details: ");
        printf("\nName: %s", S->employeetype[i].name);
        printf("\nID: %u", S->employeetype[i].ID);
        printf("\nPosition: %s", S->employeetype[i].position);
        printf("\nSalary: $%.2f", S->employeetype[i].salary);
        printf("\nHours Worked: %d\n", S->employeetype[i].hours);
    }
    else {
        printf("\nEmployee with ID %u not found\n", A);
    }
}

void displaypayroll(EmployeeRecordtype S) {
    float total = 0;
    int i;
    for (i = 0; i < S->count; i++) {
        total += S->employeetype[i].salary;
    }

    printf("Total Payroll: $%.2f\n", total);
}

int main() {
    EmployeeRecordtype ER = initList();

    if (ER == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    unsigned int id;
    unsigned int search;
    do {
        printf("\n1. Add employee\n");
        printf("2. Delete employee\n");
        printf("3. Search employee\n");
        printf("4. Display total payroll\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (ER->count < SIZE) {
                ER->employeetype[ER->count] = add_employee();
                ER->count++;
            }
            else {
                printf("The list is full!\n");
            }
            break;
        case 2:
            printf("Enter employee ID to delete: ");
            scanf("%u", &id);
            delete_employee(ER, id);
            break;
        case 3:
            printf("Enter employee ID to search : ");
            scanf("%u", &search);
            search_employee(ER, search);
            break;
        case 4:
            displaypayroll(ER);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    free(ER); // Freeing allocated memory before exiting
    return 0;
}


EmployeeRecordtype initList() {
    EmployeeRecordtype employeeRec = (EmployeeRecordtype)malloc(sizeof(EmployeeRecordtype));
    if (employeeRec != NULL) {
        employeeRec->count = 0;
    }
    return employeeRec;
}


Employee add_employee() {
    Employee newEmp;

    printf("Enter employee name: ");
    scanf("%s", newEmp.name);

    printf("Enter employee ID: ");
    scanf("%u", &newEmp.ID);

    printf("Enter employee position: ");
    scanf("%s", newEmp.position);

    printf("Enter employee salary: ");
    scanf("%f", &newEmp.salary);

    printf("Enter employee hours worked: ");
    scanf("%d", &newEmp.hours);

    printf("Employee added\n");
    return newEmp;
}

void delete_employee(EmployeeRecordtype A, unsigned int x) {
    int i, pos, y;
    for (i = 0; i < A->count && x != A->employeetype[i].ID; i++);

    if (i < A->count) {
        pos = i;
        for (y = pos + 1; y < A->count; y++) {
            memmove(&A->employeetype[y - 1], &A->employeetype[y], sizeof(Employee));
        }
        (A->count)--;
        printf("\nEmployee deleted\n");
    }
    else {
        printf("\nEmployee with ID %u not found\n", x);
    }
}