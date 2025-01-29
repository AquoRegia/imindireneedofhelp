#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"


void main(){
    int choice, value;
    char name;

    while (1) {
      
        printf("1. Create a new list\n");
        printf("2. Append value to a list\n");
        printf("3. Remove the last value from a list\n");
        printf("4. Print a list\n");
        printf("5. Free a list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a name for the new list: ");
                scanf(" %c", &name);  
                create_ll(name);
                
                break;
            case 2:
                printf("Enter the name of the list to append to: ");
                scanf(" %c", &name);
                printf("Enter the value to append: ");
                scanf("%d", &value);

                linked_list* appended_list = find_list(name);
                if (appended_list == NULL)
                {
                    printf("List '%c' not found.\n", name);
                }
                else{
                    appendto_ll(appended_list, value);
                }
                break;
            case 3:
                printf("Enter the name of the list to remove from: ");
                scanf(" %c", &name);

                linked_list* removed_list = find_list(name);
                if (removed_list == NULL)
                {
                    printf("List '%c' not found.\n", name);
                }
                else{
                    removefrom_ll(removed_list);
                }
                break;
            case 4:
                printf("Enter the name of the list to print: ");
                scanf(" %c", &name);
                linked_list* printed_list = find_list(name);
                 if (printed_list == NULL)
                {
                    printf("List '%c' not found.\n", name);
                }
                else{
                    print_ll(printed_list);
                }
                break;
            case 5:
                printf("Enter the name of the list to free: ");
                scanf(" %c", &name);
                linked_list* freed_list = find_list(name);
                 if (freed_list == NULL)
                {
                    printf("List '%c' not found.\n", name);
                }
                else{
                    free_ll(freed_list);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
}
}
}