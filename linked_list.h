#pragma once
#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* last;
};

void Append(struct Node* head, struct Node* tail, int value) {
    if(head == NULL) {
        head = (struct Node*) malloc(sizeof(struct Node));
        tail = head;
    } else {
        struct Node* toAdd = (struct Node*) malloc(sizeof(struct Node));
        toAdd->value = value;
        tail->next = toAdd;
        toAdd->last = tail;
        tail = toAdd;
    }
}

void Prepend(struct Node* head, struct Node* tail, int value) {
    if(head == NULL) {
        head = (struct Node*) malloc(sizeof(struct Node));
        tail = head;
    } else {
        struct Node* toAdd = (struct Node*) malloc(sizeof(struct Node));
        toAdd->value = value;
        toAdd->next = head;
        head->last = toAdd;
        head = toAdd;
    }
}

void Reverse(struct Node* head, struct Node* tail) {
    if(head == NULL) {
        printf("Nothing to reverse, please add some elements\n");
    } else {
        struct Node* ptr = tail;
        struct Node* transitional;
        while(ptr->last == NULL) {
            transitional = ptr->last;
            ptr->last = ptr->next;
            ptr->next = transitional;
            ptr = ptr->next;
        }
        head = transitional;
        head = tail;
        tail = transitional;
    }
}

void addElement(struct Node* head, int value, int index) {
    if (index <= 0) {
        printf("Please introduce a valid positive index\n");
    }

    struct Node* ptr = head;
    int element = 1;

    while(ptr->next != NULL) {
        if(element == index) {
            struct Node* toAdd = (struct Node*) malloc(sizeof(struct Node));
            toAdd->value = value;
            toAdd->last = ptr->last;
            toAdd->next = ptr;
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

void removeElement(struct Node* head, int index) {
    if (index <= 0) {
        printf("Please introduce a valid positive index\n");
    }

    struct Node* ptr = head;
    int element = 1;

    while(ptr->next != NULL) {
        if(element == index) {
            struct Node* toRemove = ptr;
            ptr->last->next = ptr->next;
            ptr->next->last = ptr->last;
            free(ptr);
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

void Sort(struct Node* head, struct Node* tail, bool asc) {
    struct Node *tempData;
    struct Node *current;
    struct Node *next;

    while (next != NULL) {
        current = head;
        next = current->next;
        while (next != NULL) {
            if (asc == true) {
                if (current->value > next->value) {
                    tempData = current;
                    current = next;
                    current->next = tempData;
                    current->last = tempData->last;
                    next = tempData;
                    next->next = current->next;
                    next->last = current;
                }
            } else {
                if (current->value < next->value) {
                    tempData = current;
                    current = next;
                    current->next = tempData;
                    current->last = tempData->last;
                    next = tempData;
                    next->next = current->next;
                    next->last = current;
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
            printf("There exists such cell with value %d at index %d", value, index);
            return true;
        }
        index++;
        ptr = ptr->next;
    }

    printf("There doesen't exist such cell with value %d", value);
    return false;
}

void combineLists(struct Node* head1, struct Node* last1, struct Node* head2, struct Node* last2) {
    last1->next = head2;
    head2->last = last1;
    last1 = last2;
    head2 = head1;
}

void Backwards(struct Node* tail) {
    struct Node* ptr = tail;

    while(ptr->last != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->last;
    }
    printf("\n");
}
