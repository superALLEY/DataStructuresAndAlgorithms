
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// d�finition de la structure de file
typedef struct node {
    char data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// initialisation d'une file vide
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// fonction pour ajouter un �l�ment � la file
void enqueue(Queue* q, char value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// fonction pour supprimer un �l�ment de la file
void dequeue(Queue* q) {
    if (q->front == NULL) {
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// fonction pour vider une file
void clearQueue(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
}

// fonction pour v�rifier si un mot est un palindrome
int isPalindrome(Queue* q) {
    char first, last;

    if (q->front == NULL || q->front->next == NULL) {
        // si la file est vide ou ne contient qu'un seul �l�ment
        return 1;
    }

    // extraire le premier et le dernier caract�re de la file
    first = q->front->data;
    last = q->rear->data;

    if (first != last) {
        // si les premiers et derniers caract�res sont diff�rents
        return 0;
    }
    else {
        // supprimer les premiers et derniers caract�res de la file
        dequeue(q);
        q->rear = q->front->next;
        dequeue(q);
        // continuer la v�rification r�cursivement avec le reste du mot
        return isPalindrome(q);
    }
}

int main() {
    char word[MAX_LEN];
    Queue q;
    int i, len;

    // initialisation de la file vide
    initQueue(&q);

    // saisie du mot � v�rifier
    printf("Entrez un mot: ");
    scanf("%s", word);

    // ajouter chaque caract�re du mot � la file
    len = strlen(word);
    for (i = 0; i < len; i++) {
        enqueue(&q, word[i]);
    }

    // v�rifier si le mot est un palindrome
    if (isPalindrome(&q)) {
        printf("%s est un palindrome\n", word);
    }
    else {
        printf("%s n'est pas un palindrome\n", word);
    }

    // vider la file
    clearQueue(&q);

    return 0;
}

