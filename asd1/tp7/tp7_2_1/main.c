#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
    //fonction
bool anagramme(char name1[20],char name2[20],int co){
    int size1=strlen(name1),size2=strlen(name2);
    if  (size1 != size2) {return false;}
    else if (!strchr(name2,name1[co])){return false;}
    else if(co==size1-1){return true;}
    else{co++;anagramme(name1,name2,co);}




}

int main()
{
    //declaratoin des variables
    char mot1[20];
    char mot2[20];
    int coo=0;
    bool verification;
    //traitement
    printf("veuillez saisir deux mots!\nle premier mot :");
    scanf(" %s",&mot1);
    printf("le deuxieme mot :");
    scanf(" %s",&mot2);

    verification=anagramme(mot1,mot2,coo);
    if(verification){
        printf("le deuxieme mot est un anagramme de le premier mots");
    }else{
        printf("le deuxieme mot n est pas  un anagramme de le premier mots");
    }

    return 0;
}
