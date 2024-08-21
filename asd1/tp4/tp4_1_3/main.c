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

 if(b==0){printf("%d\n",N);}


}

int main()
{
   int c,x,k;
   scanf("%d%d",&x,&k);
   for(int h=x;h<=k;h++  ){
 premier(h);
}
    return 0;
}
