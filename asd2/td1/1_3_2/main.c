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


listeetuding eclaterliste(listeetuding l,int p){

     if(p==l.longue){
        return l;
     }

    else{if(l.etudiant[p].moyennne>=10){
        l.admis[l.longue1]=l.etudiant[p];
        l.longue1++;
       return  eclaterliste(l,p+1);
    }else{
        l.ajourne[l.longue2]=l.etudiant[p];
        l.longue2++;
        return eclaterliste(l,p+1);
    }}

}



int main()
{
listeetuding etud;
etud.longue=10;
etud.longue1=0;
etud.longue2=0;
int k=0;

for(int i=0;i<10;i++){
    scanf("%f",&etud.etudiant[i].moyennne);}
etud=eclaterliste(etud,k);

for(int i=0;i<etud.longue1;i++){
    printf("%.2f admis \n",etud.admis[i].moyennne);}
for(int i=0;i<etud.longue2;i++){
    printf("%.2f ajournee\n",etud.ajourne[i].moyennne);}
    return 0;
}
