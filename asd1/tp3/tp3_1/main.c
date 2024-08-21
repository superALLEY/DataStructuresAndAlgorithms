#include <stdio.h>
#include <stdlib.h>

int main()
{int A,B,C,N,X;


    printf("veuillez saisir un nombre naturel\n");
    do{scanf("%d",&N);}while(N<0);
C=0;
     for(B=1;B<=N/2;B++)  {if(N%B==0){
            C=B+C;
        }
     }
if(C==N) {printf("le nombre  %d et parfait",N);}
else{printf("\nle nombre %d nest pas parfait",N);}




    return 0;
}
