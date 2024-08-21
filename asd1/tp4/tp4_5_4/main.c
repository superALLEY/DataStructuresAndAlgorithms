#include <stdio.h>
#include <stdlib.h>
float pui(float a ,float b){
    float k=1;
for(int i=1;i<=b;i++){
    k=a*k;


}return k;


}
int main()
{
  float A,B,x;
  scanf("%f%f",&A,&B);
  x=pui(A,B);
  printf("%f",x);
    return 0;
}
