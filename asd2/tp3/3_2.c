#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}


void deleteAtFront(Node** head) {
    if (*head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    Node* nextNode = (*head)->next;
    temp->next = nextNode;
    free(*head);
    *head = nextNode;
}


void search(Node* head, int data) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    Node* temp = head;
    do {
        if (temp->data == data) {
            printf("L'element %d existe dans la liste.\n", data);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("L'element %d n'existe pas dans la liste.\n", data);
}


void display(Node* head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;

    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    
    printf("Liste : ");
    display(head);

    
    deleteAtFront(&head);
    printf("Apres suppression du premier element : ");
    display(head);

    
    search(head, 30);
    search(head, 50);

    // Ajouter un nouvel élément à la fin de la liste
    insertAtEnd(&head, 50);
    printf("Apres ajout d'un nouvel element : ");
    display(head);

    return 0;
}