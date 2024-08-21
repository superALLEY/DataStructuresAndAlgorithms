#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,D,S;
    int E=7500,F=6000,G=9500,H=8000,I=3000,J=300;
    printf("veuillez nombre de chambres individuelles\n");
    scanf("%d",&A);
    printf("\nveuillez nombre de chambres doubles,\n");
    scanf("%d",&B);
    printf("\nnombre d’enfants et nombre de nuits\n");
    scanf("%d%d",&C,&D);

    if (A>=3){
            if( B>=4){
S=(A*F+B*H+I*(C-1))*D;
            }else{
S=(A*F+B*G+I*(C-1))*D;
            }

    }else{
            if(B>=4){
S=(A*E+B*H+I*(C-1))*D;
            }else{
S=(A*E+B*G+I*(C-1)+J*C)*D;
            }
    };
printf("le prix totale a payé est :%d da" ,S);









    return 0;
}
