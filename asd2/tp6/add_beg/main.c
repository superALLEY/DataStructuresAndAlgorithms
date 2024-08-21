#include <stdio.h>
#include <stdlib.h>

// Définition des structures
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

// Fonction pour chercher un élément dans la file
int chercherElem(File* file, int elem) {
    ElementFile* courant = file->debut;
    while (courant != NULL) {
        if (courant->valeur == elem) {
            return 1; // L'élément est trouvé dans la file
        }
        courant = courant->suivant;
    }
    return 0; // L'élément n'est pas trouvé dans la file
}

// Fonction pour ajouter un élément au début de la file
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
    // Ajout d'éléments dans la file
    enfiler(&file, 1);
    enfiler(&file, 2);
    enfiler(&file, 3);
    enfiler(&file, 4);
    // Affichage de la file
    printf("File initiale : ");
    afficher_file(&file);
    // Recherche d'un élément dans la file
    if (chercherElem(&file, 3)) {
        printf("L'élément 3 est présent dans la file.\n");
    } else {
        printf("L'élément 3 n'est pas présent dans la file.\n");
    }
    // Ajout d'un élément au début de la file
    ajouterDeb(&file, 0);
    printf("File après ajout au début : ");
    afficher_file(&file);
    return 0;
}
