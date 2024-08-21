#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Personne {
    char nom[20];
    int age;
    struct Personne *prev;
    struct Personne *next;
} Personne;

Personne* creer_personne(char nom[], int age) {
    Personne *personne = (Personne*) malloc(sizeof(Personne));
    strcpy(personne->nom, nom);
    personne->age = age;
    personne->prev = NULL;
    personne->next = NULL;
    return personne;
}

void ajouter_personne(Personne **debut, Personne **fin, char nom[], int age) {
    Personne *personne = creer_personne(nom, age);
    if (*debut == NULL) {
        *debut = *fin = personne;
    } else {
        (*fin)->next = personne;
        personne->prev = *fin;
        *fin = personne;
    }
}

void supprimer_personne(Personne **debut, Personne **fin, char nom[]) {
    Personne *personne = *debut;
    while (personne != NULL) {
        if (strcmp(personne->nom, nom) == 0) {
            if (personne == *debut) {
                *debut = personne->next;
            } else if (personne == *fin) {
                *fin = personne->prev;
            }
            if (personne->prev != NULL) {
                personne->prev->next = personne->next;
            }
            if (personne->next != NULL) {
                personne->next->prev = personne->prev;
            }
            free(personne);
            return;
        }
        personne = personne->next;
    }
}

void trier_personnes(Personne **debut) {
    Personne *personne = *debut;
    Personne *suivant;
    while (personne != NULL) {
        suivant = personne->next;
        while (suivant != NULL) {
            if (personne->age > suivant->age) {
                char tmp_nom[20];
                int tmp_age = personne->age;
                strcpy(tmp_nom, personne->nom);
                personne->age = suivant->age;
                strcpy(personne->nom, suivant->nom);
                suivant->age = tmp_age;
                strcpy(suivant->nom, tmp_nom);
            }
            suivant = suivant->next;
        }
        personne = personne->next;
    }
}

void afficher_personnes(Personne *debut) {
    Personne *personne = debut;
    while (personne != NULL) {
        printf("%s %d\n", personne->nom, personne->age);
        personne = personne->next;
    }
    printf("\n");
}

int main() {
    Personne *debut = NULL;
    Personne *fin = NULL;

    // Ajouter des personnes
    ajouter_personne(&debut, &fin, "Alice", 25);
    ajouter_personne(&debut, &fin, "Bob", 32);
    ajouter_personne(&debut, &fin, "Charlie", 19);

    printf("Liste de personnes avant modification :\n");
    afficher_personnes(debut);

    // Ajouter une personne à la fin de la liste
    ajouter_personne(&debut, &fin, "David", 40);
    printf("Liste de personnes après l'ajout de David :\n");
    afficher_personnes(debut);






// Supprimer une personne de la liste
supprimer_personne(&debut, &fin, "Charlie");
printf("Liste de personnes après la suppression de Charlie :\n");
afficher_personnes(debut);

// Trier la liste en fonction de l'âge
trier_personnes(&debut);
printf("Liste de personnes triée par âge :\n");
afficher_personnes(debut);

// Libérer la mémoire allouée
Personne *personne = debut;
while (personne != NULL) {
    Personne *suivant = personne->next;
    free(personne);
    personne = suivant;
}

return 0;
}