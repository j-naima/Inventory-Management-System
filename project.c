#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void main()
{
    int choice;

    printf("\n\n\n");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                                           =");
    printf("\n\t\t\t\t        =               WELCOME TO                  =");
    printf("\n\t\t\t\t        =          Inventory Management             =");
    printf("\n\t\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t\t        =                                           =");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    while (1)
    {
        printf("\n\n\t\t\t---------------------------------------------------------------------------\n");

        printf("\n\t\t\t\t\t1. Add item in inventory.\n");
        printf("\t\t\t\t\t2. Display inventory item.\n");
        printf("\t\t\t\t\t3. Delete item from inventory.\n");
        printf("\t\t\t\t\t4. Update item information from inventory.\n");
        printf("\t\t\t\t\t5. Purchase item from inventory.\n");
        printf("\t\t\t\t\t6. Check inventory and restock quantity.\n");
        printf("\t\t\t\t\t7. Search item from inventory using sku number.\n");
        printf("\t\t\t\t\t8. Exit.\n");

        printf("\n\t\t\t----------------------------------------------------------------------------");

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
            delete_inventory_item();
            break;
        case 4:
            update_inventory_item();
            break;
        case 5:
            purchase_item();
            break;
        case 6:
            checkInventory_and_add_quantity();
            break;
        case 7:
            search_in_inventory();
            break;
        case 8:
            printf("Goodbye see you again ^_^");
            exit(0);
        default:
            printf("\nWrong choice!!!. Enter right choice.\n\n");
        }
    }
}
