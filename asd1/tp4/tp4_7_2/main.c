#include <stdio.h>
#include <stdlib.h>
float pui(float a ,float b){
    float k=1;
for(int i=1;i<=b;i++){
    k=a*k;


}return k;}


float fonc(int m){

    float b;

if (m==1){return 0;}
float p=0;
for (int i=2;i<=m;i++){

    b=i*p+pui(-1,i);
    p=b;
}
return p;
}




int main()
{
   int x;
scanf("%d",&x);
float p;
 p=fonc(x);
printf("%f",p);
    return 0;
}
