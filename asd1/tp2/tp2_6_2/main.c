#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,a,b,c,i,k;
    X=0;
    a=10;
    k=0;
    b=0;


    while(b<a){


        if(X%2==0){
        printf("\n%d",X);
        k=k+X;
        b=b+1;
        }
X=X+1;

    }
    printf("\n%d",k);

    return 0;
}
