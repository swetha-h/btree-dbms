#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.c"
#include "insert.c"
#include "search.c"
#include "delete.c"

btreeNode *root;
btreeNode *result;

void main()
{
    root = (btreeNode *)malloc(sizeof(btreeNode));
    (*root).leaf = 1; //it's a leaf, it has no children as of now
    (*root).n = 1;    // Update number of keys in root

    int ch, value;
    char choice;
menu:
    printf("=====MENU=====\n");
    printf("1.Insert\n2.Delete\n3.Search\n4.Exit");
    switch (ch)
    {
    case 1:
    ins:
        printf("Enter value to be inserted\n");
        scanf("%d", &value);
        insert(root, value);
        printf("Insert another value?Press y to insert,any other key to go back to menu\n");
        if (choice == 'y')
            goto ins;
        else
            goto menu;
        break;
    case 2:
    del:
        printf("Enter the value to be deleted\n");
        scanf("%d", &value);
        removeKey(root, value);
        printf("Delete another value?Press y to delete,any other key to go back to menu\n");
        if (choice == 'y')
            goto del;
        else
            goto menu;
        break;
    case 3:
    search:
        printf("Enter the value to be searched\n");
        scanf("%d", &value);
        result = search(root, value);
        if (result != NULL)
            printf("Value %d is present\n", &result);
        else
            printf("Value not present in tree");
        printf("Search for another value?Press y to search,any other key to go back to menu\n");
        if (choice == 'y')
            goto search;
        else
            goto menu;
        break;
    case 4:
        printf("Exiting Menu");
        exit(0);
    default:
        printf("Invalid input.Try again\n");
        goto menu;
    }
}