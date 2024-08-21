#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 bool pair(int n){
if (n%2==0){return true;}


else{return false;}


}
int main()
{int x,k=0;
float i=0;


scanf("%d",&x);
while(x!=0){
if(pair(x)==1){
    i = i+1;
}
scanf("%d",&x);
k=k+1;
}
printf("%.1f\n",i);
i=i*100/k;
printf("%.2f %",i);

    return 0;
}
