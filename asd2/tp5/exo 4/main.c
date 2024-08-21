#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* debut;
    Node* fin;
} File;

File* creerFile() {
    File* f = (File*)malloc(sizeof(File));
    f->debut = NULL;
    f->fin = NULL;
    return f;
}

void enfiler(File* f, int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    if (f->debut == NULL) {
        f->debut = n;
        f->fin = n;
    } else {
        f->fin->next = n;
        f->fin = n;
    }
}

int defiler(File* f) {
    if (f->debut == NULL) {
        printf("File vide\n");
        return -1;
    }
    Node* n = f->debut;
    int val = n->data;
    f->debut = n->next;
    if (f->debut == NULL) {
        f->fin = NULL;
    }
    free(n);
    return val;
}

void afficherFile(File* f) {
    Node* n = f->debut;
    printf("File : ");
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int chercherElem(File* f, int val) {
    Node* n = f->debut;
    while (n != NULL) {
        if (n->data == val) {
            return 1;
        }
        n = n->next;
    }
    return 0;
}

void ajouterDeb(File* f, int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->next = f->debut;
    f->debut = n;
    if (f->fin == NULL) {
        f->fin = n;
    }
}

int main() {
    File* f = creerFile();

    enfiler(f, 10);
    enfiler(f, 20);
    enfiler(f, 30);
    afficherFile(f);

    int val = defiler(f);
    printf("Valeur defilee : %d\n", val) ;
    afficherFile(f);

    int trouve = chercherElem(f, 21);
    if (trouve) {
        printf("Element trouve\n");
    } else {
        printf("Element non trouve\n")   ;
    }

    ajouterDeb(f, 5);
    afficherFile(f);

    return 0;
}
