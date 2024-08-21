#include <stdio.h>
#include <stdlib.h>

typedef struct tabEtud{
int identifiant;
char nom[20];
int temps;

}tabEtud;
int main()
{
    float temp=0;

    int n,exo;
    tabEtud etud[15];
    for(int i=0;i<15;i++){
      //  scanf("%s",&etud[i].nom);
        //scanf("%d",&etud[i].identifiant);
        scanf("%d",&etud[i].temps);

    }
  for(int i=0;i<15;i++){

        temp=etud[i].temps+temp;

    }int h,m,s;
    temp=temp/15;
    h=temp/3600;
    m=(temp-h*3600)/60;
    s=(temp-h*3600-m*60);
    printf("la moyenne des duree consacree par les etudiants pour preparer la serie tp est : %d h %d min %d sec" ,h,m,s);


    return 0;
}
