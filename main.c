#include <stdio.h>
#include "linked_list.h"

int main() {
    struct Node* head = NULL;

    Append(&head, 55);
    printList(head);
    Append(&head, 33);
    printList(head);
    Prepend(&head, 69);
    printList(head);
    Prepend(&head, 420);
    printList(head);
    Reverse(&head);
    printList(head);
    printList(head);
    Prepend(&head, 407);
    printList(head);
    Append(&head, 16);
    printList(head);
    addElement(&head, 99, 3);
    printList(head);
    removeElement(&head, 5);
    printList(head);
    removeElement(&head, 2);
    printList(head);
//    Sort(&head, true);
//    printList(head);
//    Sort(&head, false);
//    printList(head);
    find(head, 100);
    find(head, 99);
//    combineLists(&head, &head2);
    Backwards(&head);
    Destroy(&head);
}