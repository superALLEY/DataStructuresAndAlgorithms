#include <stdio.h>
#include <stdlib.h>

int main()
{int k;
    printf("veuillez saisir k : ");
    scanf("%d \n",&k);
    int tab[20];
  for(int i=0;i<20;i++){
    scanf("%d",            &tab[i]);
  }

   for(int i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}
    printf("\n");
    int c;

  for(int i=0;i<20-k;i++){
    tab[19-i]=tab[19-k-i];

  }for (int i=0;i<k;i++){tab[i]=0;}

     for(int  i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}



    return 0;
}
