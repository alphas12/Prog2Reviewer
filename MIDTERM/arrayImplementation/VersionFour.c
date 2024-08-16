#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int accountNumber;
    float balance;
} BankAccount;

typedef struct {
    BankAccount *accounts;
    int count;
} *BankList; //Version Four

BankList initList();
BankList populateList();
void addAccount(BankList, BankAccount);
void deleteAccount(BankList, int);
void displayAccounts(BankList);
void depositMoney(BankList, int, float);
void withdrawMoney(BankList, int, float);

int main() {
    BankList L = initList();

    if (L == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    L = populateList();
    int choice;

    do {
        printf("\n1. Add account\n");
        printf("2. Delete account\n");
        printf("3. Display accounts\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");
        printf("Choose a number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                BankAccount newAccount;
                printf("Enter the account number: ");
                scanf("%d", &newAccount.accountNumber);
                printf("Enter the balance: ");
                scanf("%f", &newAccount.balance);
                addAccount(L, newAccount);
                break;
            }
            case 2: {
                int accNum;
                printf("Enter the account number to delete: ");
                scanf("%d", &accNum);
                deleteAccount(L, accNum);
                break;
            }
            case 3:
                displayAccounts(L);
                break;
            case 4: {
                int accNum;
                float amount;
                printf("Enter the account number: ");
                scanf("%d", &accNum);
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                depositMoney(L, accNum, amount);
                break;
            }
            case 5: {
                int accNum;
                float amount;
                printf("Enter the account number: ");
                scanf("%d", &accNum);
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                withdrawMoney(L, accNum, amount);
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

BankList initList() {
    BankList temp = (BankList)malloc(sizeof(*temp));
    if (temp != NULL) {
        temp->accounts = (BankAccount *)malloc(SIZE * sizeof(BankAccount));
        temp->count = 0;
    }
    return temp;
}

BankList populateList() {
    BankAccount initialAccounts[] = {{123456, 122633.25}, {272361, 25000.00}, {872, 0.00}};
    int size = sizeof(initialAccounts) / sizeof(BankAccount);

    BankList L = initList();
    if (L == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        addAccount(L, initialAccounts[i]);
    }

    return L;
}

void addAccount(BankList L, BankAccount account) {
    if (L->count < SIZE) {
        L->accounts[L->count] = account;
        L->count++;
    } else {
        printf("List is full\n");
    }
}

void deleteAccount(BankList L, int elem) {
    int i;
    for (i = 0; i < L->count && elem != L->accounts[i].accountNumber; i++) {}
    if (i < L->count) {
        for (int j = i; j < L->count - 1; j++) { //L->count - 1 refers to the second to the last index of the array
            L->accounts[j] = L->accounts[j + 1];
        }
        L->count--;
    } else {
        printf("Account Number not found\n");
    }
}

void displayAccounts(BankList L) {
    if (L->count == 0) {
        printf("No accounts to display.\n");
    } else {
        printf("\nAccount Number\tBalance\n");
        for (int i = 0; i < L->count; i++) {
            printf("%d\t\t%.2f\n", L->accounts[i].accountNumber, L->accounts[i].balance);
        }
    }
}

void depositMoney(BankList L, int accNum, float amount) {
    int i;
    for (i = 0; i < L->count; i++) {
        if (L->accounts[i].accountNumber == accNum) {
            L->accounts[i].balance += amount;
            printf("Deposited %.2f to account %d. New balance: %.2f\n", amount, accNum, L->accounts[i].balance);
        } else {
            printf("Account Number %d not found\n", accNum);
        }
    }
}

void withdrawMoney(BankList L, int accNum, float amount) {
    int i;
    for (i = 0; i < L->count; i++) {
        if (L->accounts[i].accountNumber == accNum) {
            if (L->accounts[i].balance >= amount) {
                L->accounts[i].balance -= amount;
                printf("Withdrew %.2f from account %d. New balance: %.2f\n", amount, accNum, L->accounts[i].balance);
            } else {
                printf("Insufficient balance in account %d\n", accNum);
            }
        } else {
              printf("Account Number %d not found\n", accNum);
        }
    }
}
