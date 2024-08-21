#include <stdio.h>
#include <stdlib.h>
float pui(float a ,float b){
    float k=1;
for(int i=1;i<=b;i++){
    k=a*k;


}return k;}


float fonc(int m){

    float k,b;

if (m==1){return 0;}
else { return m*fonc(m-1)+pui(-1,m);
}
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
