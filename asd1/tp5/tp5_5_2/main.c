#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[20];
  for(int i=0;i<20;i++){
    scanf("%d",            &tab[i]);
  }

   for(int i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}
    printf("\n");
    int c;

  for(int i=0;i<19;i++){
    tab[19-i]=tab[18-i];

  }tab[19-19]=0;

     for(int  i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}



    return 0;
}
