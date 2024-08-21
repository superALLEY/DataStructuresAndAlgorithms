
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
   for (int i=n-1;i>=1;i--){
        for  (int j=2;j<=i;j++){
                if(tab[j-1]>tab[j]){
             tmp=tab[j-1];
             tab[j-1]=tab[j];
             tab[j]=tmp;}
        }

   }
      for (int i=0;i<n;i++){
           printf("%d \t",tab[i]);
   }

    return 0;
}
