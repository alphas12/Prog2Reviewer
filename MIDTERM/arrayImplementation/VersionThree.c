#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


typedef struct Item {
    char name[20];
    unsigned int ID;
    int price;
    int quantity;
    char supplier[20];
} Itemtype;


typedef struct {
    Itemtype *items;
    int count;
    int max;
}ItemInfo; //Version Three

Itemtype add_item();
void search_byID(ItemInfo );
void displayList(ItemInfo );
void generateReport(ItemInfo );
ItemInfo initList(){
    ItemInfo A;
    A.count = 0;
    A.max = SIZE;
    return A;
}

int main() {

    ItemInfo L = initList();
    L.items = (Itemtype *)malloc(L.max * (sizeof(Itemtype)));
    int choice;

    do {
        
        printf("Inventory Management System\n");
        printf("1. Add new item\n");
        printf("2. Search item by ID\n");
        printf("3. Display Info\n");
        printf("4. Generate Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (L.count < L.max) {
                    L.items[L.count] = add_item();
                    L.count++;
                } else {
                    printf("Inventory is full!\n");
                }
                break;
            case 2:
                search_byID(L);
                break;
            case 3:
                displayList(L);
                break;
            case 4:
                generateReport(L);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid input!\n");
        }
    } while (choice != 5);

    return 0;
}


Itemtype add_item() {
    Itemtype L;
    printf("Enter the ID of the item: ");
    scanf("%u", &L.ID);

    printf("Enter the name of the item: ");
    scanf("%s", L.name);

    printf("Enter the price of the item: ");
    scanf("%d", &L.price);

    printf("Enter the quantity of the item: ");
    scanf("%d", &L.quantity);

    printf("Enter the supplier of the item: ");
    scanf("%s", L.supplier);

    printf("Item added to inventory\n\n");
    return L;
}

void search_byID(ItemInfo L) {
    unsigned int Id;
    printf("Enter the ID of the item to search: ");
    scanf("%u", &Id);

    int i;
    for (i = 0; i < L.count && Id != L.items[i].ID; i++) {}

    if (i < L.count && L.items[i].ID == Id) {
        printf("Item found:\n");
        printf("Name: %s\n", L.items[i].name);
        printf("ID: %u\n", L.items[i].ID);
        printf("Price: %d\n", L.items[i].price);
        printf("Quantity: %d\n", L.items[i].quantity);
        printf("Supplier: %s\n",L.items[i].supplier);
    } else {
        printf("Item not found.\n");
    }
}

void displayList(ItemInfo L) {
    printf("Items in inventory:\n");
    for (int i = 0; i < L.count; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", L.items[i].name);
        printf("ID: %u\n", L.items[i].ID);
        printf("Price: %d\n", L.items[i].price);
        printf("Quantity: %d\n", L.items[i].quantity);
        printf("Supplier: %s\n", L.items[i].supplier);
        printf("\n");
    }
}

