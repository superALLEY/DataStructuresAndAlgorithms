#include <stdio.h>
#include <stdlib.h>

int main()
{
   float tab[10];
    int p;
    for(int i=0;i<10;i++){

        scanf("%f" ,&tab[i]);

    }
    float max=tab[0] ;

        for(int i=0;i<10;i++){



                if (tab[i]>max){
                        max =tab[i];
                        p=i+1;

    }}
 printf("le plus grand element de tableau est %.2f\n dans les positions suivantes\n",max);
    for(int i=0;i<10;i++){



                if (tab[i]==max){
                       printf("%d\n",i+1);


    }}

    return 0;
}
