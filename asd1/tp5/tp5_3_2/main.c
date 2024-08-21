#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool fonc(int a){
    int n=0;
for (int i=1;i<a;i++){
    if(a%i==0){
        n=i+n;
    }



}
if (n==a){return    true;}
else{return false;}


}
int main()
{ int c=0;
    int tab[1000];



  for(int i=0;i<1000;i++){
        if(fonc(i)){tab[c]=i;
        c=c+1;}
    }
int k=1000;
 for (c;c<k;c++){

    tab[c]=-20;
 }
for(int i=0;i<1000;i++){
    printf("tab[%d]= %d \n",i,tab[i]);

}

    return 0;
}
