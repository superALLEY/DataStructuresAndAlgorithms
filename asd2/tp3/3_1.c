#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct client {
    char nom[50];
    char email[50];
    char adresse[100];
    float montant;
    struct client* suivant;
} Client;


Client* creer_client(char nom[], char email[], char adresse[], float montant) {
    Client* nouveau_client = (Client*)malloc(sizeof(Client));
    strcpy(nouveau_client->nom, nom);
    strcpy(nouveau_client->email, email);
    strcpy(nouveau_client->adresse, adresse);
    nouveau_client->montant = montant;
    nouveau_client->suivant = NULL;
    return nouveau_client;
}


void ajouter_client(Client** debut, char nom[], char email[], char adresse[], float montant) {
    Client* nouveau_client = creer_client(nom, email, adresse, montant);
    if (*debut == NULL) {
        *debut = nouveau_client;
    } else {
        Client* actuel = *debut;
        while (actuel->suivant != NULL) {
            actuel = actuel->suivant;
        }
        actuel->suivant = nouveau_client;
    }
}


void supprimer_client(Client** debut, char email[]) {
    if (*debut == NULL) {
        return;
    }
    Client* actuel = *debut;
    Client* precedent = NULL;
    while (actuel != NULL && strcmp(actuel->email, email) != 0) {
        precedent = actuel;
        actuel = actuel->suivant;
    }
    if (actuel == NULL) {
        return;
    }
    if (precedent == NULL) {
        *debut = actuel->suivant;
    } else {
        precedent->suivant = actuel->suivant;
    }
    free(actuel);
}



int main() {

    Client* debut = NULL;

    ajouter_client(&debut, "mouad", "mouad@gmail.com", "555 uv 11", 50);

    ajouter_client(&debut, "haroun", "haroun@gmail.com", "666 uv 12", 100);


    ajouter_client(&debut, "fares", "fares@gmail.com", "777 uv 13", 200);

    supprimer_client(&debut, "mouad@gmail.com");
    Client* root = debut;
    while (root != NULL) {
        printf("%s (%s) - %s : %.2f DA\n", root->nom, root->email, root->adresse, root->montant);
        root = root->suivant;
    }
    return 0;
}