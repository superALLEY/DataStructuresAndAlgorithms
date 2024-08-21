#include <stdio.h>
#include <stdlib.h>

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
{int a,b,d;
float x;


   scanf("%d%d",&a,&b);
   x=fact(a)/(fact(b)*fact(a-b));
   printf("%f",x);



    return 0;
}
