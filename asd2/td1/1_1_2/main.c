#include <stdio.h>
#include <stdlib.h>
#define lmax 100



typedef struct livre{
int id;
int annee;
char auteur[20];
char Me[20];

}livre;
typedef struct listelivres{
livre LIVRE[lmax];
int longu;
}listelivres;




listelivres inserdebut(listelivres l,livre e){

for(int i=l.longu;i>0;i--){
    l.LIVRE[i]=l.LIVRE[i-1];
     //printf("%s \n%s \n%d \n%d \n",l.LIVRE[i].auteur,l.LIVRE[i].Me,l.LIVRE[i].annee,l.LIVRE[i].id);
}
l.LIVRE[0]=e;
l.longu=l.longu+1;
return l;}






int main()
{
    listelivres Livre;
    Livre.longu=0;
    livre e;
    int co=0;
    while(co<5){
    if(Livre.longu<lmax){
    printf("veuillez saisir le nouveau livre num : %d et ses informations\n1 : auteur \n2 : maison dedition \n3 : annee \n4 : id\n",co+1);
    scanf("%s %s %d %d",&e.auteur,&e.Me,&e.annee,&e.id );
    Livre=inserdebut(Livre,e);
    }else{
    printf("il nya pas despace pour dautres livres");
    }co++;
    }

    for(int i = 0;i<5;i++){
        printf("%s \n%s \n%d \n%d \n",Livre.LIVRE[i].auteur,Livre.LIVRE[i].Me,Livre.LIVRE[i].annee,Livre.LIVRE[i].id);

    }

    return 0;
}
