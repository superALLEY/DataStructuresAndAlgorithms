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
}
l.LIVRE[0]=e;
l.longu=l.longu+1;
return l;}

listelivres inserfin(listelivres l,livre e){

l.LIVRE[l.longu]=e;
l.longu=l.longu+1;
return l;}

listelivres inserpos(listelivres l,livre e,int pos){

for(int i=l.longu;i>pos;i--){
    l.LIVRE[i]=l.LIVRE[i-1];
}
l.LIVRE[pos-1]=e;
l.longu=l.longu+1;
return l;}

listelivres inserapr(listelivres l,livre e){
int p;
for (int i=0 ; i<l.longu;i++ ){
    if(l.LIVRE[i].id==378){
        p=i;break;
    }
}
for(int i=l.longu;i>p+1;i--){
    l.LIVRE[i]=l.LIVRE[i-1];
}
l.LIVRE[p+1]=e;
l.longu=l.longu+1;
return l;}

listelivres inseravnt(listelivres l,livre e){
int p;
for (int i=0 ; i<l.longu;i++ ){
    if(l.LIVRE[i].id==378){
        p=i;break;
    }
}
for(int i=l.longu;i>p-1;i--){
    l.LIVRE[i]=l.LIVRE[i-1];
}
l.LIVRE[p-1]=e;
l.longu=l.longu+1;
return l;}




int main()
{
    listelivres Livre;
    Livre.longu=0;
    livre e;
    if(Livre.longu<lmax){
    printf("veuillez saisir le nouveau livre et ses informations\n1 : auteur \n2 : maison dedition \n3 : annee \n4 : id\n");
    scanf("%s %s %d %d",&e.auteur,&e.Me,&e.annee,&e.id );
    Livre=inserdebut(Livre,e);
    }else{
    printf("il nya pas despace pour dautres livres");
    }


    return 0;
}
