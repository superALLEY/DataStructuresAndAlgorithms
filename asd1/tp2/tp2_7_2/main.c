#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I,N,X;
    printf("veuillez saisir un nombre naturel\n");
    do {
        scanf("%d",&N);
    }while (N<0);
    I=1;
    X=2;
    while(I==1 && X<N){
        if( N%X==0){I=0;}
        X=X+1;
    }
    if(I==1 || N==2) {printf("le nombre entré est premier");}
    else {printf("le nombre est non premier");}

    return 0;
}
