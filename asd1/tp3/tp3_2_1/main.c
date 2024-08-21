#include <stdio.h>
#include <stdlib.h>

int main()
{int N,i,b;
    printf("ecrire la valeure de N\n");
    do{scanf("%d",&N);}while(N<0);
  for (i=1;i<=N;i++){
    printf("*\n");
    for (b=1;b<=i;b++){
         printf("*");

    }

  } printf("*");
    return 0;
}
