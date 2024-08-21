#include <stdio.h>
#include <stdlib.h>

int main()
{
  int tab[50];
  int i,n;
  printf("veuillez taper la dim du tab\n");
  scanf("%d",&n);
  for (i =0; i<n;i++){
        printf("element un du tab %d :" ,i+1);
    scanf("%d",&tab[i]);

  }
  int ech;
  do{ ech=0;
        for(i=0;i<n-1;i++){

            if(tab[i]>tab[i+1]){
                int tmp;
                tmp=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=tmp;
                ech++;
            }

        }
  }while(ech>0);
  for (i=0;i<n;i++){
  printf("%7d",tab[i]);
  printf("\t");
  }
    return 0;
}
