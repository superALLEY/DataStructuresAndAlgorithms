#include <stdio.h>
#include <stdlib.h>
float pui(float a ,float b){
    float k=1;
for(int i=1;i<=b;i++){
    k=a*k;


}return k;}


int fact(int n){
if(n==0){
    return 1;
}else if (n==1) {
return 1;
}
else{
return n*fact(n-1);
}}





int main()
{
  float A,B,x;
  scanf("%f%f",&A,&B);
  x=0;
 for(int f=0;f<=B;f++){
    x=(pui(A,f)/fact(f))+x;



 }printf("%f",x);
    return 0;
}
