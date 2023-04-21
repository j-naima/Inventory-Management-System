typedef struct
{
    char name[100];
    int sku_num;
    float cost;
    int quantity;
} inventoryItem;

void insert_item_in_inventory()
{
    inventoryItem inventory;

    FILE *fp;
    fp = fopen("inventory.txt", "ab+");

    if (fp == NULL)
    {
        printf("\n\t\t\t\tInsert file is not open\n");
        return;
    }

    printf("\t\t\t\tAdd new item in inventory:\n\n");

    fflush(stdin);
    printf("Enter item name: ");
    gets(inventory.name);

    printf("Enter item SKU number(should be unique): ");
    scanf("%d", &inventory.sku_num);

    printf("Enter item cost: ");
    scanf("%f", &inventory.cost);

    printf("Enter item quantity: ");
    scanf("%d", &inventory.quantity);

    int found = 0;
    inventoryItem temp;

    while (fread(&temp, sizeof(temp), 1, fp) == 1)
    {
        if (temp.sku_num == inventory.sku_num)
        {
            found = 1;
            printf("\n\t\t\t\tThis item (sku number: %d) is already in inventory\n", inventory.sku_num);
            break;
        }
    }

    if (found == 0)
    {
        fwrite(&inventory, sizeof(inventory), 1, fp);
        printf("\n\t\t\t\tSuccessfully added item in inventory.\n\n");
    }

    fclose(fp);
}

void display_inventory_item()
{
    inventoryItem inventory;

    FILE *fp;
    fp = fopen("inventory.txt", "rb");

    if (fp == NULL)
    {
        printf("\n\t\t\t\tDisplay file is not open\n");
    }

    printf("\n\t\t\t\tHere is all item that are available in inventory: \n");

    printf("\n\t\t\tItem name\tSKU Number\tCost of each\t\tQuantity\n");
    while (fread(&inventory, sizeof(inventory), 1, fp) > 0)
    {
        printf("\t\t\t%s \t\t %d \t\t %.2f \t\t\t %d\n", inventory.name, inventory.sku_num, inventory.cost, inventory.quantity);
    }

    fclose(fp);
}

void search_in_inventory()
{
    inventoryItem inventory;

    FILE *fp;
    fp = fopen("inventory.txt", "rb+");

    if (fp == NULL)
    {
        printf("\n\t\t\t\tSearch inventory file is not open");
    }

    int skuNum, flag = 0;
    printf("Enter sku number of that item you want to search: ");
    scanf("%d", &skuNum);

    while (fread(&inventory, sizeof(inventory), 1, fp) > 0 && flag == 0)
    {
        if (inventory.sku_num == skuNum)
        {
            printf("\n\t\t\t\t\tSuccessfully data found\n");
            printf("\n\t\t\tItem name\tSKU Number\tCost of each\t\tQuantity\n");
            flag = 1;
            printf("\t\t\t%s \t\t %d \t\t %.2f \t\t\t %d\n", inventory.name, inventory.sku_num, inventory.cost, inventory.quantity);
        }
    }

    if (flag == 0)
    {
        printf("\n\t\t\t\t\tSku number (%d) data is not found.\n", skuNum);
    }

    fclose(fp);
}

void update_inventory_item()
{
    inventoryItem inventory;

    FILE *fp;
    fp = fopen("inventory.txt", "rb+");

    if (fp == NULL)
    {
        printf("\n\t\t\t\tUpdate file is not open\n");
    }

    int skuNum, flag = 0;

    printf("\nEnter sku number of the item you want to update: ");
    scanf("%d", &skuNum);

    while (fread(&inventory, sizeof(inventory), 1, fp) > 0 && flag == 0)
    {
        if (inventory.sku_num == skuNum)
        {
            flag = 1;

            printf("\n\t\t\t\tUpdate item information in inventory:\n\n");

            fflush(stdin);
            printf("Enter item new name: ");
            gets(inventory.name);

            printf("Enter item new SKU number: ");
            scanf("%d", &inventory.sku_num);

            printf("Enter item new cost: ");
            scanf("%f", &inventory.cost);

            printf("Enter item new quantity: ");
            scanf("%d", &inventory.quantity);

            fseek(fp, -(long)sizeof(inventory), 1);
            fwrite(&inventory, sizeof(inventory), 1, fp);

            printf("\n\t\t\t\t Item information successfully updated\n");

            break;
        }
    }

    if (flag == 0)
    {
        printf("\n\n\t\t\t\tItem information not found\n");
    }

    fclose(fp);
}

void delete_inventory_item()
{
    inventoryItem inventory;

    FILE *fp, *f_temp;
    fp = fopen("inventory.txt", "rb");
    f_temp = fopen("inventory_copy.txt","ab+");
    
    if (fp == NULL || f_temp == NULL)
    {
        printf("\n\t\t\t\tDelete file is not open.\n");
    }

    int skuNUmber, flag = 0;
    printf("\nEnter sku number of that item you want to delete: ");
    scanf("%d", &skuNUmber);

    while (fread(&inventory, sizeof(inventory), 1, fp) > 0)
    {
        if (inventory.sku_num == skuNUmber)
        {
            flag = 1;
            printf("\n\t\t\t\tItem successfully deleted");
        }

        else
        {
            fwrite (&inventory, sizeof(inventory), 1, f_temp);
        }
    }

    if (flag == 0)
    {
        printf("\n\t\t\t\tNo search data found.");
    }

    fclose(fp);
    fclose(f_temp);

    remove("inventory.txt");
    rename("inventory_copy.txt", "inventory.txt");

    
    /*
        user(4) == inventory(4)

        box1(m)        box2(T) --> main
        4           3
        3           2
        2           1
        1

        swap
        temp = n1
        n1 = n2
        n2 = n1

        delete

        *fp     *temp
        *fp == user

        others --> *temp

        a   1
2       b   2  
        c   3
        d   4

    */
}