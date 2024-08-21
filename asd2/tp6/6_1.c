
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// définition de la structure de file
typedef struct elementFile {
    char data;
    struct elementFile* next;
} elementFile;

typedef struct File {
    elementFile* debut;
    elementFile* fin;
} File;

// initialisation d'une file vide
void initFile(File* q) {
    q->debut = NULL;
    q->fin = NULL;
}

// fonction pour ajouter un élément à la file
void enfiler_char(File* q, char value) {
    elementFile* new_elementFile = (elementFile*)malloc(sizeof(elementFile));
    new_elementFile->data = value;
    new_elementFile->next = NULL;
    if (q->fin == NULL) {
        q->debut = new_elementFile;
        q->fin = new_elementFile;
    }
    else {
        q->fin->next = new_elementFile;
        q->fin = new_elementFile;
    }
}

// fonction pour supprimer un élément de la file
void defiler(File* q) {
    if (q->debut == NULL) {
        return;
    }
    elementFile* temp = q->debut;
    q->debut = q->debut->next;
    if (q->debut == NULL) {
        q->fin = NULL;
    }
    free(temp);
}

// fonction pour vider une file
void vider_file(File* q) {
    while (q->debut != NULL) {
        defiler(q);
    }
}

// fonction pour vérifier si un mot est un palindrome
int isPalindrome(File* q) {
    char first, last;

    if (q->debut == NULL || q->debut->next == NULL) {
        // si la file est vide ou ne contient qu'un seul élément
        return 1;
    }

    // extraire le premier et le dernier caractère de la file
    first = q->debut->data;
    last = q->fin->data;

    if (first != last) {
        // si les premiers et derniers caractères sont différents
        return 0;
    }
    else {
        // supprimer les premiers et derniers caractères de la file
        defiler(q);
        q->fin = q->debut->next;
        defiler(q);
        // continuer la vérification récursivement avec le reste du mot
        return isPalindrome(q);
    }
}

int main() {
    char word[MAX_LEN];
    File q;
    int i, len;

    // initialisation de la file vide
    initFile(&q);

    // saisie du mot à vérifier
    printf("Entrez un mot: ");
    scanf("%s", word);

    // ajouter chaque caractère du mot à la file
    len = strlen(word);
    for (i = 0; i < len; i++) {
        enfiler_char(&q, word[i]);
    }

    // vérifier si le mot est un palindrome
    if (isPalindrome(&q)) {
        printf("%s est un palindrome\n", word);
    }
    else {
        printf("%s n'est pas un palindrome\n", word);
    }

    // vider la file
    vider_file(&q);

    return 0;
}
