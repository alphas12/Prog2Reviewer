#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char LName[16], FName[24], MI;
} Nametype;

typedef struct {
    Nametype name;
    int ID;
    char course[8];
    int Year;
} Studtype;

typedef struct {
    Studtype studArr[SIZE];
    int count;
} StudList;




StudList initList();
StudList populateList();
void displayList(StudList);
void insertAtFirst(StudList *, Studtype);
Studtype deleteElem(StudList *, int);
int deleteAllCourse(StudList *, char []);
void sortList (StudList *);
void insertSorted(StudList *, Studtype);

int main() {
    StudList L = initList();
    L = populateList();

    printf("Original List:\n");
    displayList(L);

    Studtype A = {{"Garcia", "James", 'M'}, 12893257, "BSCS", 1};
    insertAtFirst(&L, A);
    printf("\nAfter Insertion:\n");
    displayList(L);

    int X = 22129423;
    Studtype deletedRecord = deleteElem(&L, X);
    if (strcmp(deletedRecord.name.LName, "XXXX") == 0){
        printf("\nStudent with ID %d not found\n", X);
    }else{
        printf("\nDeleted Record:\n%s %s %c %d %s %d\n", deletedRecord.name.LName, deletedRecord.name.FName, deletedRecord.name.MI, deletedRecord.ID, deletedRecord.course, deletedRecord.Year);
    }
    printf("\nAfter Deletion:\n");
    displayList(L);

    printf("\nDeleting all students with course BSCS, Total Deleted: %d\n", deleteAllCourse(&L, "BSCS"));
    printf("\nAfter Deleting BSCS Students:\n");
    displayList(L);

    printf("\nSorting List:\n");
    sortList(&L);
    displayList(L);

    Studtype B = {{"Ali", "Khan", 'A'}, 12345678, "BSCS", 1};
    insertSorted(&L, B);
    printf("\nAfter Insertion in Sorted Order:\n");
    displayList(L);

    return 0;
}

StudList initList(){
    StudList list;
    list.count = 0;
    return list;
}


StudList populateList() {
    Studtype sArr[] = {
        {{"Pastoriza", "Alnino", 'E'}, 11111111, "BSIS", 1},
        {{"Advincula", "Monicah", 'D'}, 22222222, "BSIS", 2},
        {{"Auza", "Marco", 'C'}, 33333333, "BSCS", 1},
        {{"Barbon", "Mart", 'A'}, 44444444, "BSCS", 1},
        {{"Elderfield", "Zeus", 'D'}, 55555555, "BSIT", 1},
    };

    int numElem = sizeof(sArr) / sizeof(Studtype);

    StudList S = {.count = numElem};

    int i;
    for(i = 0; i < numElem; i++){
         S.studArr[i] = sArr[i]; // Ass
    }

    return S;
}


void displayList(StudList L) {
    int i;

   printf("%-12s%-16s%-16s%-3s%-5s%-10s\n", "ID NUMBER", "LAST NAME", "FIRST NAME", "MI", "COURSE", "YR LEVEL");

    for (i = 0; i < L.count; i++) {
        printf("%-12d", L.studArr[i].ID);
        printf("%-16s", L.studArr[i].name.LName);
        printf("%-16s", L.studArr[i].name.FName);
        printf("%-3c", L.studArr[i].name.MI);
        printf("%-8s", L.studArr[i].course);
        printf("%-16d", L.studArr[i].Year);
        printf("\n");
    }
    printf("Count: %d\n", L.count);
}

void insertAtFirst(StudList *L, Studtype A) {
    if (L->count < SIZE) {
        memmove(&L->studArr[1], &L->studArr[0], L->count * sizeof(Studtype));
        L->studArr[0] = A;
        L->count++;
    }
}

Studtype deleteElem(StudList *L, int ID) {
    Studtype dummy = {{"XXXX", "XXXX", 'X'}, 0, "XXXX", 0}; // Dummy record
    int i, pos, y;
    for (i = 0; i < L->count && ID != L->studArr[i].ID; i++){}

    if (i < L->count) {
        pos = i;
        for (y = pos + 1; y < L->count; y++) {
            memmove(&L->studArr[y - 1], &L->studArr[y], sizeof(Studtype));
        }
        L->count--;
        return L->studArr[pos];
    }
    return dummy;
}

int deleteAllCourse(StudList *L, char course[]) {
    int i, deletedCount = 0;
    for (i = 0; i < L->count; i++) {
        if (strcmp(L->studArr[i].course, course) == 0) {
            deleteElem(L, L->studArr[i].ID);
            deletedCount++;
            i--; 
        }
    }
    return deletedCount;
}

void sortList(StudList *L) { //selection sort
    int i, j, min_idx;
    Studtype temp;
    for (i = 0; i < L->count - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < L->count; j++) {
            if (strcmp(L->studArr[j].name.LName, L->studArr[min_idx].name.LName) < 0) //L->studArr[min_idx].name.LName < L->studArr[j].name.LName
                min_idx = j;
        }
        if (min_idx != i) {
            temp = L->studArr[i];
            L->studArr[i] = L->studArr[min_idx];
            L->studArr[min_idx] = temp;
        }
    }
}

void insertSorted(StudList *L, Studtype A) {
    int i;
    for (i = L->count - 1; i >= 0 && strcmp(L->studArr[i].name.LName, A.name.LName) > 0; i--) {
        L->studArr[i + 1] = L->studArr[i];
    }
    L->studArr[i + 1] = A;
    L->count++;
}