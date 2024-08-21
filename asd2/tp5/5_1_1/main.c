#include <stdio.h>
#include <stdlib.h>

typedef struct elementFile {
    int valeur;

    struct elementFile* suivant;
} ElementFile;

typedef struct file {
    ElementFile* debut;
    ElementFile* fin;
} File;

File creerFile() {
    File file;
    file.debut = NULL;
    file.fin = NULL;
    return file;
}

void eliminer_doublons(File* file) {
    ElementFile* courant = file->debut;
    while (courant != NULL) {
        ElementFile* suivant = courant->suivant;
        while (suivant != NULL) {
            if (suivant->valeur == courant->valeur) {
                ElementFile* supprimer = suivant;
                suivant = suivant->suivant;
                supprimer_element_file(file, supprimer);
            } else {
                suivant = suivant->suivant;
            }
        }
        courant = courant->suivant;
    }
}
void vider_file(File* file) {
    ElementFile* elementCourant = file->debut;
    while (elementCourant != NULL) {
        ElementFile* elementSuivant = elementCourant->suivant;
        free(elementCourant);
        elementCourant = elementSuivant;
    }
    file->debut = NULL;
    file->fin = NULL;
}
void supprimer_element_file(File* file, int valeur) {
    ElementFile* elementCourant = file->debut;
    ElementFile* elementPrecedent = NULL;
    while (elementCourant != NULL) {
        if (elementCourant->valeur == valeur) {
            if (elementPrecedent == NULL) {
                file->debut = elementCourant->suivant;
            } else {
                elementPrecedent->suivant = elementCourant->suivant;
            }
            if (elementCourant == file->fin) {
                file->fin = elementPrecedent;
            }
            ElementFile* elementASupprimer = elementCourant;
            elementCourant = elementCourant->suivant;
            free(elementASupprimer);
        } else {
            elementPrecedent = elementCourant;
            elementCourant = elementCourant->suivant;
        }
    }
}

File copier(File f) {
    File f_copie;
    f_copie.debut = NULL;
    f_copie.fin = NULL;
    ElementFile* courant = f.debut;
    while (courant != NULL) {
        ElementFile* nouvel_element = malloc(sizeof(ElementFile));
        nouvel_element->valeur = courant->valeur;
        nouvel_element->suivant = NULL;
        if (f_copie.debut == NULL) {
            f_copie.debut = nouvel_element;
            f_copie.fin = nouvel_element;
        } else {
            f_copie.fin->suivant = nouvel_element;
            f_copie.fin = nouvel_element;
        }
        courant = courant->suivant;
    }
    return f_copie;
}


int somme_iterative_file(File* file) {
    int somme = 0;
    ElementFile* elementCourant = file->debut;
    while (elementCourant != NULL) {
        somme += elementCourant->valeur;
        elementCourant = elementCourant->suivant;
    }
    return somme;
}void concatener(File* file1, File* file2) {
    if (file1->debut == NULL) {
        file1->debut = file2->debut;
        file1->fin = file2->fin;
    } else if (file2->debut != NULL) {
        file1->fin->suivant = file2->debut;
        file1->fin = file2->fin;
    }
    file2->debut = NULL;
    file2->fin = NULL;
}

int somme_recursive_file(ElementFile* debut) {
    if (debut == NULL) {
        return 0;
    }
    return debut->valeur + somme_recursive_file(debut->suivant);
}
void enfiler(File* file, int valeur) {
    ElementFile* nouvelElement = (ElementFile*) malloc(sizeof(ElementFile));
    nouvelElement->valeur = valeur;
    nouvelElement->suivant = NULL;
    if (file->fin == NULL) {
        file->debut = nouvelElement;
        file->fin = nouvelElement;
    } else {
        file->fin->suivant = nouvelElement;
        file->fin = nouvelElement;
    }
}

int defiler(File* file) {
    if (file->debut == NULL) {
        return 0;
    }
    int valeurDefilee = file->debut->valeur;
    ElementFile* ancienDebut = file->debut;
    file->debut = file->debut->suivant;
    free(ancienDebut);
    if (file->debut == NULL) {
        file->fin = NULL;
    }
    return valeurDefilee;
}

void inverser(File* f) {
    ElementFile* courant = f->debut;
    ElementFile* precedent = NULL;
    ElementFile* suivant = NULL;
    f->fin = f->debut;
    while (courant != NULL) {
        suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }
    f->debut = precedent;
}

void triRapide(File* file) {
    if (file == NULL || file->debut == NULL) {
        return;
    }
    int pivot = defiler(file);
    File inferieur = creerFile();
    File superieur = creerFile();
    int valeurCourante;
    while ((valeurCourante = defiler(file)) != 0) {
        if (valeurCourante < pivot) {
            enfiler(&inferieur, valeurCourante);
        } else {
            enfiler(&superieur, valeurCourante);
        }
    }
    triRapide(&inferieur);
    triRapide(&superieur);
    while ((valeurCourante = defiler(&inferieur)) != 0) {
        enfiler(file, valeurCourante);
    }
    enfiler(file, pivot);
    while ((valeurCourante = defiler(&superieur)) != 0) {
        enfiler(file, valeurCourante);
    }
}

void afficherFile(File* file) {
    ElementFile* courant = file->debut;
    printf("[");
    while (courant != NULL) {
        printf("%d", courant->valeur);
        courant = courant->suivant;
        if (courant != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void permuteCirc(File* q, int N) {
    if (q == NULL || q->debut == NULL || q->fin == NULL)
        return;
    int i;
    for (i = 1; i <= N; i++) {
        int data = defiler(q);
        enfiler(q, data);
    }
}
void ajouterDeb(File* file, int elem) {
    ElementFile* nouvel_element = (ElementFile*) malloc(sizeof(ElementFile));
    nouvel_element->valeur = elem;
    nouvel_element->suivant = file->debut;
    if (file->debut == NULL) {
        file->fin = nouvel_element;
    }
    file->debut = nouvel_element;
}

int chercherElem(File* file, int elem) {
    ElementFile* courant = file->debut;
    while (courant != NULL) {
        if (courant->valeur == elem) {
            return 1;
        }
        courant = courant->suivant;
    }
    return 0;
}


int main() {
    File file = creerFile();
    enfiler(&file, 7);
    enfiler(&file, 1);
    enfiler(&file, 4);
    enfiler(&file, 9);
    enfiler(&file, 2);
    printf("File avant tri rapide : ");
    afficherFile(&file);
    triRapide(&file);
    printf("File apres tri rapide : ");
    afficherFile(&file);
    File f=copier(file);
    afficherFile(&f);
    inverser(&f);
    afficherFile(&f);
    permuteCirc(&f,2);
    afficherFile(&f);


    return 0;
}
