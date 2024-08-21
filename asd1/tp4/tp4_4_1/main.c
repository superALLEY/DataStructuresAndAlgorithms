#include <stdio.h>
#include <stdlib.h>

float fonc(int x){
if (x==0){return 56;}
else{
    return fonc(x-1)-0.8715;
}



}


int main()
{
float c;
    int n;
    scanf("%d",&n);
    c=fonc(n);
    printf("%f",c);
    return 0;
}
