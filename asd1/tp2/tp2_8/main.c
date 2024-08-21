#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I,N,X,A,V,Q,S,K;
    printf("veuillez saisir un nombre naturel\n");
    do {
        scanf("%d",&N);
    }while (N<0);
    I=1;
    X=2;
    V=0;
    K=0;

    while(N>V){
            I=1;
            A=2;
    while(I==1 && A<X){
        if( X%A==0){I=0;}
        A=A+1;
    }
    if(I==0 ) {printf("\n%d",X);
    S=1;

                for (Q=2;Q<=X;++Q){
        S=Q*S;


    }


     printf("\nla factoriele de %d est: %d",X,S);
    K=K+S;
    V=V+1;

    }
    X=X+1;
    }
 printf("\nla somme des factorielles des %d premier  nombres non premier est :%d",N,K);
    return 0;
}




