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
   for(int i=0;i<=9;i++){
    c=fonc(i);
    printf("%f\n",c);}
    return 0;
}
