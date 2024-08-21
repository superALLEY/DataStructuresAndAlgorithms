#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("veuillez saisir n : ");
    scanf("%d \n",&n);
    int tab[20];
  for(int i=0;i<20;i++){
    scanf("%d",            &tab[i]);
  }

   for(int i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}
    printf("\n");
    int c;

  for(int i=n;i<20;i++){
    tab[i]=tab[1+i];

  }//for (int i=0;i<n;i++){tab[19-i]=0;}
  tab[19]=0;

     for(int  i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}



    return 0;
}
