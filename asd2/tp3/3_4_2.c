#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Commande {
    char nom_client[50];
    char plat[50];
    float prix;
    char heure_commande[10];
    struct Commande *prev;
    struct Commande *next;
} Commande;

Commande *getLatestCommand(Commande *commandes, char *nom_client) {
    if (commandes == NULL) {
        return NULL;
    }
    Commande *current = commandes;
    Commande *latest = NULL;
    do {
        if (strcmp(current->nom_client, nom_client) == 0) {
            if (latest == NULL || strcmp(current->heure_commande, latest->heure_commande) > 0) {
                latest = current;
            }
        }
        current = current->next;
    } while (current != commandes);
    return latest;
}

int main() {
    
    Commande *commandes = NULL;

    Commande *commande1 = (Commande *) malloc(sizeof(Commande));
    strcpy(commande1->nom_client, "haroun");
    strcpy(commande1->plat, "Pizza");
    commande1->prix = 500.0;
    strcpy(commande1->heure_commande, "13:30");
    commande1->prev = NULL;
    commande1->next = NULL;
    commandes = commande1;
    
    Commande *commande2 = (Commande *) malloc(sizeof(Commande));
    strcpy(commande2->nom_client, "mouad");
    strcpy(commande2->plat, "Burger");
    commande2->prix = 400;
    strcpy(commande2->heure_commande, "12:45");
    commande2->prev = commande1;
    commande2->next = commande1;
    commande1->next = commande2;
    commande1->prev = commande2;
  
    Commande *latest_commande = getLatestCommand(commandes, "mouad");
    if (latest_commande != NULL) {
        printf("La commande la plus recente pour mouad est pour le plat %s et a ete commandee a %s pour un prix de %.2f DA.\n",
            latest_commande->plat, latest_commande->heure_commande, latest_commande->prix);
    } else {
        printf("Aucune commande n'a ete trouvee pour mouad.\n");
    }
    
    Commande* current = commandes;
    do {
        Commande *next = current->next;
        free(current);
        current = next;
    } while (current != commandes);
    return 0;
}