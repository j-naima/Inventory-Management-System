#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void main()
{
    int choice;

    printf("\n\t\t\t\t Hi! Welcome to inventory management system \n");

    while (1)
    {
        printf("\n1. Add item in inventory.\n");
        printf("2. Display inventory item.\n");
        printf("3. Search item from inventory using sku number.\n");
        printf("4. Update item information from inventory.\n");
        printf("5. Delete item from inventory.\n");
        printf("6. Check inventory and restock quantity.\n");
        printf("7. Purchase item from inventory.\n");
        printf("8. Exit.\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {      
        case 1:
            insert_item_in_inventory();
            break;

        case 2:
            display_inventory_item();
            break;

        case 3:
            search_in_inventory();
            break;
            
        case 4:
            update_inventory_item();
            break;
            
        case 5:
            delete_inventory_item();
            break;
            
        case 6:
            //checkInventory_and_add_quantity();
            break;

        case 7:
            //purchase_item();
            break;

        case 8:
            printf("Goodbye see you again..!");
            exit(0);

        default:
            printf("\nWrong choice!!!. Enter right choice.\n\n");
        }
    }
}