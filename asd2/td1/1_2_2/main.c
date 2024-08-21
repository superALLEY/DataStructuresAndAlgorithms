#include <stdio.h>
#include <stdlib.h>
#define lmax 100



typedef struct etud{
int id;
char nom[20];
char prenom[20];
float TD,TP,examen,moy;
char cour[20],etd[20],etp[20];

}etud;
typedef struct listeetud{
etud ETUD[lmax];
int longu;
}listeetud;


listeetud moyenne(listeetud l){


   l.ETUD[0].moy=0.6*l.ETUD[0].examen+(l.ETUD[0].TD+l.ETUD[0].TP)/2;


return l;}

listeetud inserdebut(listeetud l,etud e){

for(int i=l.longu;i>0;i--){
    l.ETUD[i]=l.ETUD[i-1];
}
l.ETUD[0]=e;
l.longu=l.longu+1;
return l;}

listeetud inserfin(listeetud l,etud e){

l.ETUD[l.longu]=e;
l.longu=l.longu+1;
return l;}

listeetud inserpos(listeetud l,etud e,int pos){

for(int i=l.longu;i>pos;i--){
    l.ETUD[i]=l.ETUD[i-1];
}
l.ETUD[pos-1]=e;
l.longu=l.longu+1;
return l;}

listeetud inserapr(listeetud l,etud e){
int p;
for (int i=0 ; i<l.ETUD;i++ ){
    if(l.ETUD[i].id==67){
        p=i;break;
    }
}
for(int i=l.ETUD;i>p+1;i--){
    l.ETUD[i]=l.ETUD[i-1];
}
l.ETUD[p+1]=e;
l.longu=l.longu+1;
return l;}

listeetud inseravnt(listeetud l,etud e){
int p;
for (int i=0 ; i<l.longu;i++ ){
    if(l.ETUD[i].id==89){
        p=i;break;
    }
}
for(int i=l.longu;i>p-1;i--){
    l.ETUD[i]=l.ETUD[i-1];
}
l.ETUD[p-1]=e;
l.longu=l.longu+1;
return l;}




int main()
{
    listeetud Etud;
    Etud.longu=0;
    etud e;
    if(Etud.longu<lmax){
    printf("veuillez saisir le nouveau etudiant et ses informations\n1 : id \n2 : nom \n3 : prenom  \n4 : TD \n5 : TP \n6 : examen \n7 : cour \n8 : etd \n9 : etp \n");
    scanf("%d %s %s %f %f %f %f %s %s %d",&e.id,&e.nom,&e.prenom,&e.TD,&e.TP,&e.examen,&e.cour,&e.etd,&e.etp );
    Etud=inserdebut(Etud,e);
    }else{
    printf("il nya pas despace pour dautres etudiant");
    }


    return 0;
}

