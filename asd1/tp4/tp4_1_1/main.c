#include <stdio.h>
#include <stdlib.h>

int premier(int N){
int i,b=0;

for (i=2;i<=N/2;i++){
    if(N%i==0){
            b=1;
            i=N;
    }
    return b;
}


}

int main()
{
   int c,x;
   scanf("%d",&x);
 c=premier(x);
   if(c==0){printf("le nombre est premier");}
   else{printf("le nombre nest pas un premier");}
    return 0;
}
