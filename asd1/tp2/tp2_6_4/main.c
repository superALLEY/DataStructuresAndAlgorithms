#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d,e;
float     somme,moyenne,produit;
scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
somme=a+b+c+d+e;
produit=a*b*c*d*e;
moyenne=somme/2;
printf("\n%f\n%f\n%f",somme,produit,moyenne);
    return 0;
}
