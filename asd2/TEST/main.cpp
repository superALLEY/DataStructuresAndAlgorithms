#include <iostream>

using namespace std;


typedef struct element
{
    float info;
    element*suiv;


};
element*p,*e,*l;
int d,vlr,i;
void ajoutf(element *&tete,float V){

e=new(element);
e->info=V;
e->suiv=NULL;

if(tete == NULL)
{
    tete = e;
}
else{
        p=tete;
        while(p->suiv!=NULL)
        {
            p=p->suiv;
        }
        p->suiv=e;
}

    }
float moyenne (element *L) {

float s=0;

int co=0;

 while (L!=NULL) {

s+=L->info;
L=L->suiv;

co++; }

return s/co;
}
element*inver (element*P, element*Y ) {

element *X;

Y = NULL;

while (P!=NULL) {

X=P;

P=P->suiv;

X->suiv=Y;

Y-X; }


return Y;}


int main(){
     element*L ,*A, *B; int d, i; float N;

cin>>d;

 cout<<"remplis la liste"<<endl;

L-NULL; for (i=0;i<d; i++) {
cin>>N;

ajoutf(L,N);


}
A=L;

cout<<"la liste avant l'inver"<<endl; while (A!=NULL) {

cout<<A->info<<endl;

A=A->suiv;

N=moyenne (L);

A=inver (L, B);

cout<<"la moyenne est s="<<N<<endl;

L=A;

cout<<"la liste apres l'inver"<<endl;
 while (L!= NULL) {

cout<<L->info<<endl;
L-L->suiv;
}
}
return 0;

}
