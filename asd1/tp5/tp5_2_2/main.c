#include <stdio.h>
#include <stdlib.h>
void fonc(){

 /*********************************************************************************************/
    char nom[100],nom1[5];
    int k=1;
    printf("veuillez saisir les nombres d'etudiants : ");

    int nbre ;
    scanf("%d",&nbre);

    printf("veuillez saisir le nom que vous voudrez verifier sa exicetence : ");

    scanf("%s ",&nom1);


      printf("veuillez saisir les noms d'etudiants \n");

      int i=0;
      char* aa;
        while (i<nbre){
            printf("veuillez saisir le nom d'etudiant num %d : ",i+1);
            scanf(" %s ",&nom);
            aa=strstr(nom,nom1);
            if(aa){k=0;}
i=i+1;
        }

    if(k==0){
        printf("ce edutiant existe");

    }

 else {printf("ce etidiant n existe pas ");}



}

int main()
{
    fonc();
    return 0;
}
