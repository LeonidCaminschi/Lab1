#pragma once
#include <stdbool.h>
#include <stddef.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* last;
};

void Append(struct Node** head, int value) {
    if((*head) == NULL) {
        (*head) = (struct Node*) malloc(sizeof(struct Node));
        (*head)->value = value;
    } else {
        struct Node* toAdd = (struct Node*) malloc(sizeof(struct Node));
        toAdd->value = value;
        struct Node *tail = *head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = toAdd;
        toAdd->last = tail;
        toAdd->next = NULL;
    }
}

void Prepend(struct Node** head, int value) {
    if(head == NULL) {
        (*head) = (struct Node*) malloc(sizeof(struct Node));
        (*head)->value = value;
    } else {
        struct Node* toAdd = (struct Node*) malloc(sizeof(struct Node));
        toAdd->value = value;
        toAdd->next = (*head);
        (*head)->last = toAdd;
        (*head) = toAdd;
    }
}

void printList(struct Node* head) {
    struct Node* ptr = head;

    while(ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void Reverse(struct Node** head) {
    if(head == NULL) {
        printf("Nothing to reverse, please add some elements\n");
    } else {
        struct Node *tail = *head;
        while (tail->next != NULL)
            tail = tail->next;

        struct Node* ptr = tail;
        struct Node* transitional;
        while(ptr != NULL) {
            transitional = ptr->last;
            ptr->last = ptr->next;
            ptr->next = transitional;
            ptr = ptr->next;
        }
        (*head) = tail;
    }
}

void addElement(struct Node** head, int value, int index) {
    if (index <= 0) {
        printf("Please introduce a valid positive index\n");
    }

    struct Node* ptr = (*head);
    int element = 1;

    while(ptr != NULL) {
        if(element == index) {
            struct Node* toAdd = (struct Node*) malloc(sizeof(struct Node));
            toAdd->value = value;
            toAdd->last = ptr->last;
            toAdd->next = ptr;
            ptr->last->next = toAdd;
            ptr->last = toAdd;
            break;
        } else {
            element++;
            ptr = ptr->next;
        }
    }

    if(element < index) {
        printf("There doesen't exist such index\n");
    }
}

void removeElement(struct Node** head, int index) {
    if (index <= 0) {
        printf("Please introduce a valid positive index\n");
    }

    struct Node* ptr = (*head);
    int element = 1;

    while(ptr->next != NULL) {
        if(element == index) {
            struct Node* toRemove = ptr;
            ptr->last->next = ptr->next;
            ptr->next->last = ptr->last;
            free(toRemove);
            break;
        } else {
            element++;
            ptr = ptr->next;
        }
    }

    if(element < index) {
        printf("There doesen't exist such index\n");
    }
}

void Sort(struct Node** head, bool asc) {
    struct Node *transitional;
    struct Node *ptr;
    struct Node *next;

    while (next != NULL) {
        ptr = (*head);
        next = ptr->next;
        while (next != NULL) {
            if (asc == true) {
                if (ptr->value > next->value) {
                    transitional = ptr;
                    ptr = next;
                    ptr->next = transitional;
                    ptr->last = transitional->last;
                    next = transitional;
                    next->next = ptr->next;
                    next->last = ptr;
                }
            } else {
                if (ptr->value < next->value) {
                    transitional = ptr;
                    ptr = next;
                    ptr->next = transitional;
                    ptr->last = transitional->last;
                    next = transitional;
                    next->next = ptr->next;
                    next->last = ptr;
                }
            }
        }
    }
}

bool find(struct Node* head, int value) {
    struct Node* ptr = head;
    int index = 1;

    while(ptr->next != NULL) {
        if(ptr->value == value) {
            printf("There exists such cell with value %d at index %d \n", value, index);
            return true;
        }
        index++;
        ptr = ptr->next;
    }

    printf("There doesen't exist such cell with value %d \n", value);
    return false;
}

void combineLists(struct Node* head1, struct Node* last1, struct Node* head2, struct Node* last2) {
    last1->next = head2;
    head2->last = last1;
    last1 = last2;
    head2 = head1;
}

void Backwards(struct Node** head) {
    struct Node *tail = *head;
    while (tail->next != NULL)
        tail = tail->next;
    struct Node* ptr = tail;

    while(ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->last;
    }
    printf("\n");
}

void Destroy(struct Node** head) {
    struct Node* ptr = (*head);

    while(ptr != NULL) {
        struct Node* toRemove = ptr;
        ptr = ptr->next;
        free(toRemove);
    }
}
