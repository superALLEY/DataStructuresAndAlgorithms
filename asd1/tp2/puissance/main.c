#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int pui(int W, int K)
{int L,H=1;

for (L=1;L<=K;L++){
   H=H*W;
}
     return H;


}
int main(int argc, char *argv[])
{int A,B,c,M;
scanf("%d%d",&A,&B);
c=pui(A,B);
printf("%d",c);


   return 0;
}

