#include <stdio.h>
#include <stdlib.h>
int prod(int pp,int m,int a,int b){


if (b==m){printf("%d",pp);}

else if ((a*a)%2==0)

{pp=a*a*pp;
prod(pp,m,a+1,b+1);}

else{ prod(pp,m,a+1,b);}




}
int main()
{
int n,p=1,c=2,h=0;
scanf("%d",&n);
 prod(p,n,c,h);


  return 0;
}
