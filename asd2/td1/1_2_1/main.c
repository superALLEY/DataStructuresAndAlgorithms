#include <stdio.h>
#include <stdlib.h>
#define lmax 1000





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
char  major[20];

}listeetud;


listeetud triid(listeetud l){
int n=l.longu;int i,max,posmax;;
while(n>0){
    max=l.ETUD[0].id;
    posmax=0;
    for(i=0;i<n;i++){
        if(l.ETUD[i].id>max){
            max=l.ETUD[i].id;
            posmax=i;
        }

    }
    for(i=posmax;i<n;i++){
        l.ETUD[i]=l.ETUD[i+1];
    }
    l.ETUD[n-1].id=max;
    n--;
}
return l;}

listeetud trimoyenne(listeetud l){
int n=l.longu;int i,max,posmax;;
while(n>0){

    max=l.ETUD[0].moy;
    posmax=0;
    for(i=0;i<n;i++){
        if(l.ETUD[i].moy>max){
            max=l.ETUD[i].moy;
            posmax=i;
        }


    }
    for(i=posmax;i<n;i++){
        l.ETUD[i]=l.ETUD[i+1];
    }
    l.ETUD[n-1].moy=max;
    n--;
}





return l;}


listeetud  major(listeetud l,int i,float moye,int idd){
        if(i==3){ strcpy(l.major,l.ETUD[idd].nom); return l;}
        else{if(l.ETUD[i].moy>moye){
         return major(l,i+1,l.ETUD[i].moy,i);
        }else{return major(l,i+1,moye,idd);}}
}





listeetud moyenne(listeetud l){
for(int i=0;i<3;i++){
   l.ETUD[i].moy=0.6*l.ETUD[i].examen+((l.ETUD[i].TD+l.ETUD[i].TP)/2)*0.4;
}

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
    int cooo=0;float moyee=-1;
    int d=0;
    for(int i=0;i < 3;i++){
    if(Etud.longu<lmax){
    printf("veuillez saisir le nouveau etudiant et ses informations\n1 : id \n2 : nom \n3 : prenom  \n4 : TD \n5 : TP \n6 : examen \n7 : cour \n8 : etd \n9 : etp \n");
    scanf("%d %s %s %f  %f %f %s %s %s",&e.id,&e.nom,&e.prenom,&e.TD,&e.TP,&e.examen,&e.cour,&e.etd,&e.etp );
    Etud=inserdebut(Etud,e);
    }else{
    printf("il nya pas despace pour dautres etudiant");
    }

    }

    Etud=moyenne(Etud);

    Etud=major(Etud,cooo,moyee,d);  for(int i=0;i < 3;i++){
  printf("%.2f\t %s hi \n",Etud.ETUD[i].moy,Etud.ETUD[i].nom);
    }
    printf("%s\n",Etud.major);
    Etud=trimoyenne(Etud);
       for(int i=0;i < 3;i++){
  printf("%.3f\t %s hi %f \n",Etud.ETUD[i].moy,Etud.ETUD[i].nom,Etud.ETUD[i].TD);
    }



    return 0;
}

