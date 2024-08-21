#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ppcd(int a, int b)
{
    int min = (a < b) ? a : b;

    for(int i=2;i <= min;++i)
        if (a % i == 0 && b % i == 0)
            return i;

    return 0;
}


int main(void)*
{
    int a;
    int b;

    printf("Entrez deux nombres : ");
    scanf("%d %d", &a, &b);

    int resultat = ppcd(a, b);

    if (resultat != 0)
        printf("Le plus petit diviseur de %d et %d est %d\n", a, b, resultat);

    printf("Entrez deux autres nombres : ");
    scanf("%d %d", &a, &b);
    resultat = ppcd(a, b);

    if (resultat != 0)
        printf("Le plus petit diviseur de %d et %d est %d\n", a, b, resultat);

    return 0;
}
