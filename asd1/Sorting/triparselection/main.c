
#include <stdio.h>

int main() {

    int n;
    scanf("%d",&n);
    int tab[n];
   for (int i=0;i<n;i++){
           scanf("%d",&tab[i]);
   }
   int mini,tmp;
   for(int i=0;i<n-1;i++){
       mini =i;
       for(int j=i+1;j<n;j++){
           if(tab[j]<tab[mini]){
               mini=j;
           }

       }
    tmp=tab[i];
    tab[i]=tab[mini];
    tab[mini]=tmp;
   }
      for (int i=0;i<n;i++){
           printf("%d \t",tab[i]);
   }

    return 0;
}
