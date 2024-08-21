#include <stdio.h>
#include <stdlib.h>
int prod(int m,int a,int b){


if (b==m){return 1;}

else if ((a*a)%2==0)

{return a*a*prod(m,a+1,b+1);}

else{return prod(m,a+1,b);}




}
int main()
{
int n,p,c=2,h=0;
scanf("%d",&n);
 p=prod(n,c,h);
 printf("%d",p);

  return 0;
}
