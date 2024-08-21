#include <stdio.h>
#include <stdlib.h>
#define tmax 200

typedef struct etuding{
char nom[20];
float moyennne;
}etuding;
typedef struct listeetuding{
etuding etudiant[tmax];
etuding admis[tmax];
etuding ajourne[tmax];
int longue1;
int longue2;
int longue;
}listeetuding;


listeetuding eclaterliste(listeetuding l){
int m=0,n=0;
  l.longue1=0;
  l.longue2=0;
for(int i=0;i<l.longue;i++){
    if(l.etudiant[i].moyennne>=10){
        l.admis[m]=l.etudiant[i];
        m++;
        l.longue1++;
    }else{
        l.ajourne[n]=l.etudiant[i];
        n++;
          l.longue2++;
    }
}
return l;}



int main()
{
listeetuding etud;
etud.longue=10;

for(int i=0;i<10;i++){
    scanf("%s %f",&etud.etudiant[i].nom,&etud.etudiant[i].moyennne);}
etud=eclaterliste(etud);

for(int i=0;i<etud.longue1;i++){
    printf("%s %.2f admis \n",etud.admis[i].nom,etud.admis[i].moyennne);}
for(int i=0;i<etud.longue2;i++){
    printf("%s %.2f ajournee\n",etud.ajourne[i].nom,etud.ajourne[i].moyennne);}
    return 0;
}
