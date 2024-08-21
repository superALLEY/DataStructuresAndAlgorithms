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
float c,k=0;
    int n;
   do{

    c=fonc(k);
    printf("%f\n",c); k=k+1;}while(c>0.3);
    return 0;
}
