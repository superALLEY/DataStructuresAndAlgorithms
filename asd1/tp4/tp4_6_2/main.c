#include <stdio.h>
#include <stdlib.h>
float pui(float a ,float b){
    float k=1;
for(int i=1;i<=b;i++){
    k=a*k;


}return k;}


float fonc(int n) {
    float h=0;
for(int g=1;g<=n;g++){

    h=h+(pui(-1,g)/(2*g));

}
return h;

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
