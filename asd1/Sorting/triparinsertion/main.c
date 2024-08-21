
#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);
    int tab[n];
   for (int i=0;i<n;i++){
           scanf("%d",&tab[i]);
   }
   int cle;
   int tmp,j;
   for (int i=1;i<n;i++){
        cle=tab[i];
        j=i-1;
    while(j>=0 && tab[j]>cle){

        tab[j+1]=tab[j];
        j=j-1;
        tab[j+1]=cle;
    }
   }
      for (int i=0;i<n;i++){
           printf("%d \t",tab[i]);
   }

    return 0;
}
