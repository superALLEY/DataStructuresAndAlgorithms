
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

int isSubList(node* list1, node* list2) {
    if (list1 == NULL || list2 == NULL) {
        return 0;
    }
    node* ptr1 = list1;
    node* ptr2 = list2;
    while (ptr2 != NULL) {
        if (ptr1 == NULL) {
            return 0;
        }
        if (ptr1->value == ptr2->value) {
            ptr2 = ptr2->next;
        }
        else {
            ptr2 = list2;
        }
        ptr1 = ptr1->next;
    }
    return 1;
}

int main()
{
    // create first linked list
    node* list1 = (node*)malloc(sizeof(node));
    list1->value = 4;
    list1->next = (node*)malloc(sizeof(node));
    list1->next->value = 2;
    list1->next->next = (node*)malloc(sizeof(node));
    list1->next->next->value = 3;
    list1->next->next->next = NULL;
    list1->next->next->next = (node*)malloc(sizeof(node));
    list1->next->next->next->value = 8;
    list1->next->next->next->next = NULL;

    // create second linked list
    node* list2 = (node*)malloc(sizeof(node));
    list2->value = 4;
    list2->next = (node*)malloc(sizeof(node));
    list2->next->value = 2;
    list2->next->next = (node*)malloc(sizeof(node));
    list2->next->next->value = 3;
    list2->next->next->next = NULL;

    // check if list1 is a sublist of list2
    if (isSubList(list1, list2)) {
        printf("list1 is a sublist of list2\n");
    }
    else {
        printf("list1 is not a sublist of list2\n");
    }

    // free memory
    node* temp;
    while (list1 != NULL) {
        temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}
