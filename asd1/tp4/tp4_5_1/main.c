#include <stdio.h>
#include <stdlib.h>

int fact(int n){
int k=1;
for (int i=2;i<=n;i++){
    k=i*k;

}return k;
}
int main()
{int x,c;
   scanf("%d",&x);
   c=fact(x);
  printf("%d",c);
    return 0;
}
