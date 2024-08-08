#include <stdio.h>

typedef union{
    char A;
    int B;
    float C;
} utype;

typedef struct {
    char memID;
    utype member;
} structUnion;

void Display(structUnion S){

    if (S.memID == 'I'){
        printf("It is an integer");
    } else if(S.memID == 'C') {
        printf("It is a character");
    } else if( S.memID == 'F'){
        printf("It is a float");
    } else {
        printf("None of the above");
    }
}
int main(){

    structUnion S;



    printf("Enter a type identifier (I for integer, C for character, F for float): ");
    scanf(" %c", &S.memID); 

    switch (S.memID) {
        case 'I':
            printf("Enter an integer: ");
            scanf("%d", &S.member.B);
            break;
        case 'C':
            printf("Enter a character: ");
            scanf(" %c", &S.member.A); 
            break;
        case 'F':
            printf("Enter a float: ");
            scanf("%f", &S.member.C);
            break;
        default:
            printf("Invalid type identifier\n");
            return 1; // Exit with an error code
    }

    Display(S);
    return 0; // Exit successfully

}
