#include <stdio.h>
#include <stdlib.h>

int main()
{
 float tab[10];
    int p;
    for(int i=0;i<10;i++){

        scanf("%f \n" ,&tab[i]);

    }
    float max=tab[0] ;

        for(int i=0;i<10;i++){



                if (tab[i]>max){
                        max =tab[i];
                        p=i+1;

    }}
 printf("le plus grand element de tableau est %.2f de la position %d\n ",max,p);


    return 0;
}
