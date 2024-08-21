#include <stdio.h>
#include <stdlib.h>

int fonc(int c,int d){
if (c==d){printf("les deux nombres sont eguax");}
    else if  (c==0)  {printf("a est le plus grand");}
    else if  (d==0)  {printf("b  est le plus grand");}
    else return fonc(c-1,d-1);


}


int main()
{
     int a,b;
scanf("%d%d",&b,&a);

fonc(a,b);
    return 0;
}
