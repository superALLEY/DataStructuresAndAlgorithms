#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int frequency;
    struct node* next;
} node;

node* sort_by_frequency(node* head) {
    // Calculer la fréquence de chaque élément
    node* curr = head;
    while (curr != NULL) {
        int freq = 0;
        node* temp = head;
        while (temp != NULL) {
            if (temp->value == curr->value) {
                freq++;
            }
            temp = temp->next;
        }
        curr->frequency = freq;
        curr = curr->next;
    }

    // Trier la liste en fonction de la fréquence
    node* new_head = NULL;
    while (head != NULL) {
        node* max_node = head;
        curr = head;
        while (curr != NULL) {
            if (curr->frequency > max_node->frequency) {
                max_node = curr;
            }
            curr = curr->next;
        }
        // Retirer le noeud avec la plus grande fréquence de la liste d'origine
        if (max_node == head) {
            head = head->next;
        } else {
            curr = head;
            while (curr->next != max_node) {
                curr = curr->next;
            }
            curr->next = max_node->next;
        }
        // Ajouter le noeud à la nouvelle liste
        max_node->next = new_head;
        new_head = max_node;
    }
    return new_head;
}

void print_list(node* head) {
    printf("[ ");
    while (head != NULL) {
        printf("(%d, %d) ", head->value, head->frequency);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    node* n1 = malloc(sizeof(node));
    node* n2 = malloc(sizeof(node));
    node* n3 = malloc(sizeof(node));
    node* n4 = malloc(sizeof(node));
    node* n5 = malloc(sizeof(node));
    n1->value = 1;
    n2->value = 3;
    n3->value = 2;
    n4->value = 3;
    n5->value = 1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    printf("Liste d'origine : ");
    print_list(n1);
    node* sorted_head = sort_by_frequency(n1);
    printf("Liste triée par fréquence : ");
    print_list(sorted_head);
    return 0;
}
