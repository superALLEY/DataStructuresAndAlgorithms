#include <stdio.h>
#include <stdlib.h>

int main()
{
  int tab[20],tab2[20];
  for(int i=0;i<20;i++){
    scanf("%d",            &tab[i]);
  }

  for(int i=0;i<20;i++){
  printf("[%d]   ",tab[i]);}
    printf("\n");
    int c;


  for (int i=0;i<20;i++){

 tab2[19-i]=tab[i];



  }
    for(int i=0;i<20;i++){
  printf("[%d]   ",tab2[i]);}


    return 0;
}
