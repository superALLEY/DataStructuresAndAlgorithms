#include <stdio.h>
#include <stdlib.h>

int main()
{int N,i,b,K;
    printf("ecrire la valeure de N\n");
    do{scanf("%d",&N);}while(N<0);
    K=1;
  for (i=1;i<=N;i++){

    printf("\n");

    for (b=1;b<=i;b++){
         printf("%d",K);
 K=K+1;
    }

  }
    return 0;
}
