#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int main(){
int i,n,max ,m,posmax;
int t[MAX];

do{
     printf("veuillez taper lz dim du tableau : ");
     scanf("%d",&n);
}while(n>MAX || n<1);

m=n;
    for(i=0;i<n;i++){
        printf("la valeur de lelement num %d :" ,i+1);
        scanf("%d",&t[i]);

    }

while(n>0){
    max=t[0];
    posmax=0;
    for(i=0;i<n;i++){
        if(t[i]>max){
            max=t[i];
            posmax=i;
        }

    }
    for(i=posmax;i<n;i++){
        t[i]=t[i+1];
    }
    t[n-1]=max;
    n--;
}
for(i=0;i<m;i++){
    printf("%7d",t[i]);
    printf("\n");

}


    return 0;
}
