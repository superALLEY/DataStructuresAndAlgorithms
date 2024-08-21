#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I,N,A;
    printf("veuillez saisir un nombre naturel\n");
    do {
        scanf("%d",&N);
    }while (N<0);
    A=1;
    for (I=2;I<=N;I++){
        A=I*A;

    }
    printf("la factorielle de nombre %d est : %d",N,A);
    return 0;
}
