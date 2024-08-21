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
{int x,c;
   scanf("%d",&x);
   c=fact(x);
  printf("%d",c);
    return 0;
}
