#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Commande {
    char nom_client[50];
    char plat[50];
    float prix;
    int heure_commande;
    struct Commande* next;
    struct Commande* prev;
} Commande;

Commande* derniere_commande(Commande* liste_commandes, char* nom_client) {
    Commande* commande_recente = NULL;
    Commande* current = liste_commandes;
    if (current == NULL) {
        printf("La liste de commandes est vide.\n");
        return NULL;
    }
    do {
        if (strcmp(current->nom_client, nom_client) == 0) {
            if (commande_recente == NULL || current->heure_commande > commande_recente->heure_commande) {
                commande_recente = current;
            }
        }
        current = current->next;
    } while (current != liste_commandes);
    if (commande_recente == NULL) {
        printf("Aucune commande trouvée pour le client %s.\n", nom_client);
    }
    return commande_recente;
}

int main() {
    // Exemple d'utilisation
    Commande* commande1 = (Commande*) malloc(sizeof(Commande));
    strcpy(commande1->nom_client, "Jean");
    strcpy(commande1->plat, "Pizza");
    commande1->prix = 12.5;
    commande1->heure_commande = 10;
    Commande* commande2 = (Commande*) malloc(sizeof(Commande));
    strcpy(commande2->nom_client, "Pierre");
    strcpy(commande2->plat, "Sushi");
    commande2->prix = 22.0;
    commande2->heure_commande = 11;
    Commande* commande3 = (Commande*) malloc(sizeof(Commande));
    strcpy(commande3->nom_client, "Jean");
    strcpy(commande3->plat, "Burger");
    commande3->prix = 8.0;
    commande3->heure_commande = 13;
    commande1->next = commande2;
    commande2->next = commande3;
    commande3->next = commande1;
    commande1->prev = commande3;
    commande2->prev = commande1;
    commande3->prev = commande2;
    Commande* derniere = derniere_commande(commande1, "Jean");
    if (derniere != NULL) {
        printf("La dernière commande de Jean est pour le plat %s et a coûté %.2f euros.\n", derniere->plat, derniere->prix);
    }
    return 0;
}