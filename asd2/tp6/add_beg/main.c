#include <stdio.h>
#include <stdlib.h>

// D�finition des structures
typedef struct elementFile {
    int valeur;
    struct elementFile* suivant;
} ElementFile;

typedef struct file {
    ElementFile* debut;
    ElementFile* fin;
} File;

// Fonctions pour manipuler la file
void enfiler(File* file, int valeur) {
    ElementFile* nouvel_element = (ElementFile*) malloc(sizeof(ElementFile));
    nouvel_element->valeur = valeur;
    nouvel_element->suivant = NULL;
    if (file->debut == NULL) {
        file->debut = nouvel_element;
    } else {
        file->fin->suivant = nouvel_element;
    }
    file->fin = nouvel_element;
}

void afficher_file(File* file) {
    printf("[ ");
    ElementFile* courant = file->debut;
    while (courant != NULL) {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    }
    printf("]\n");
}

// Fonction pour chercher un �l�ment dans la file
int chercherElem(File* file, int elem) {
    ElementFile* courant = file->debut;
    while (courant != NULL) {
        if (courant->valeur == elem) {
            return 1; // L'�l�ment est trouv� dans la file
        }
        courant = courant->suivant;
    }
    return 0; // L'�l�ment n'est pas trouv� dans la file
}

// Fonction pour ajouter un �l�ment au d�but de la file
void ajouterDeb(File* file, int elem) {
    ElementFile* nouvel_element = (ElementFile*) malloc(sizeof(ElementFile));
    nouvel_element->valeur = elem;
    nouvel_element->suivant = file->debut;
    if (file->debut == NULL) {
        file->fin = nouvel_element;
    }
    file->debut = nouvel_element;
}

// Fonction main pour tester les fonctions chercherElem et ajouterDeb
int main() {
    File file;
    file.debut = NULL;
    file.fin = NULL;
    // Ajout d'�l�ments dans la file
    enfiler(&file, 1);
    enfiler(&file, 2);
    enfiler(&file, 3);
    enfiler(&file, 4);
    // Affichage de la file
    printf("File initiale : ");
    afficher_file(&file);
    // Recherche d'un �l�ment dans la file
    if (chercherElem(&file, 3)) {
        printf("L'�l�ment 3 est pr�sent dans la file.\n");
    } else {
        printf("L'�l�ment 3 n'est pas pr�sent dans la file.\n");
    }
    // Ajout d'un �l�ment au d�but de la file
    ajouterDeb(&file, 0);
    printf("File apr�s ajout au d�but : ");
    afficher_file(&file);
    return 0;
}
