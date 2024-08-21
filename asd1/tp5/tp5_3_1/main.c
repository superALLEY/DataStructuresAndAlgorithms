#include <stdio.h>
#include <stdlib.h>
int fonc(int a){
    int n=0;
for (int i=1;i<a;i++){
    if(a%i==0){
        n=i+n;
    }



}
if (n==a){printf("le nombre est parfait");}
else{printf("le nombre nest pas parfait");}


}
int main()
{
    int x;
    scanf("%d",&x);
    fonc(x);
    return 0;
}
