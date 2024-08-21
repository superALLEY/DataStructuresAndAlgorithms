#include <stdio.h>
#include <stdlib.h>

void premier(int N){
int i;
int b=0;
for (i=2;i<=N/2;i++){
    if(N%i==0){
            b=1;
            i=N;
    }
}

 if(b==0){printf("le nombre est premier");}
   else{printf("le nombre nest pas un premier");}

}

int main()
{
   int c,x;
   scanf("%d",&x);
 premier(x);
    return 0;
}
