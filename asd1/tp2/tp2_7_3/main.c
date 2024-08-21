#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I,N,X,A,V;
    printf("veuillez saisir un nombre naturel\n");
    do {
        scanf("%d",&N);
    }while (N<0);
    I=1;
    X=2;
    V=0;


    while(N>V){
            I=1;
            A=2;
    while(I==1 && A<X){
        if( X%A==0){I=0;}
        A=A+1;
    }
    if(I==1 || X==2) {printf("\n%d",X);
    V=V+1;

    }
    X=X+1;
    }

    return 0;
}
