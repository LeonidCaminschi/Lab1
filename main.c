#include <stdio.h>
#include "linked_list.h"

int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;

    int option = 0;
    int list = 1;
    while (1) {
        printf("Double linked list for 10 hopeful\n"
               "1) Change modified list\n"
               "2) Append an element to list\n"
               "3) Prepend an element to list\n"
               "4) Reverse the order of the list\n"
               "5) Add an elementt to a certain index\n"
               "6) Remove an element from a certain index\n"
               "7) Sort the List\n"
               "8) Find an element in the given list\n"
               "9) Combine 2 lists in 1 modify only the first list\n"
               "10) Read the list in a backwards order\n"
               "11) Print the list in current format\n"
               "12) Save data to external file\n"
               "13) Get data from external file\n"
               "0) Exit\n"
               "Please choose your option: "
        );
        scanf("%d", &option);

        switch (option) {
            case 0: {
                Destroy(&head);
                Destroy(&head2);
                return 1;
            }
            case 1: {
                if (list == 1) {
                    list = 2;
                    break;
                }
                if (list == 2) {
                    list = 1;
                    break;
                }
            }
            case 2: {
                printf("Please input the appending value: ");
                int value;
                scanf("%d", &value);
                if(list == 1) Append(&head, value);
                if(list == 2) Append(&head2, value);
                break;
            }
            case 3: {
                printf("Please input the prepending value: ");
                int value;
                scanf("%d", &value);
                if(list == 1) Prepend(&head, value);
                if(list == 2) Prepend(&head2, value);
                break;
            }
            case 4: {
                if(list == 1) Reverse(&head);
                if(list == 2) Reverse(&head2);
                printf("Reversed the list at your command");
                break;
            }
            case 5: {
                printf("Please input the value: ");
                int value;
                scanf("%d", &value);
                printf("Please input in the index: ");
                int index;
                scanf("%d", &index);
                if(list == 1) addElement(&head, value, index);
                if(list == 2) addElement(&head2, value, index);
                break;
            }
            case 6: {
                printf("Please input in the index: ");
                int index;
                scanf("%d", &index);
                if(list == 1) removeElement(&head, index);
                if(list == 2) removeElement(&head2, index);
                break;
            }
            case 7: {
                if(list == 1) Sort(&head, true);
                if(list == 2) Sort(&head2, true);
                printf("Sorted the list at your command");
                break;
            }
            case 8: {
                printf("Please input the value you want to find: ");
                int value;
                scanf("%d", &value);
                if(list == 1) find(head, value);
                if(list == 2) find(head2, value);
                break;
            }
            case 9: {
                combineLists(&head, &head2);
                printf("The lists were combined at your request, modified only 1st list");
                break;
            }
            case 10: {
                if(list == 1) Backwards(&head);
                if(list == 2) Backwards(&head2);
                break;
            }
            case 11: {
                if(list == 1) printList(head);
                if(list == 2) printList(head2);
                break;
            }
            case 12: {
                printf("Please input string filename: ");
                char filename[20];
                scanf("%s", filename);
                if(list == 1) saveToFile(head, filename);
                if(list == 2) saveToFile(head2, filename);
                break;
            }
            case 13: {
                printf("Please input string filename: ");
                char filename[20];
                scanf("%s", filename);
                if(list == 1) getFromFile(&head, filename);
                if(list == 2) getFromFile(&head2, filename);
                break;
            }
            default: {
                printf("Bafoon please look over the instructions again");
            }
        }
    }
}