#include <stdio.h>
#include <stdlib.h>

#define MaxTableau 8

int main()
{
    int K,L,I,J,Inversion,ecart,Temporaire;
    int Tableau[MaxTableau] = {15, 10, 23, 2, 8, 9, 14, 16};
    printf("Avant:");

    for(K = 0; K < MaxTableau; K++) printf("%i, ",Tableau[K]);

    Inversion = 0;
    ecart = MaxTableau;
    do {
        ecart >>= 1;
        do {
            Inversion = 0;
            for(I = 0; I <= MaxTableau - ecart - 1; I++) {
                J = I + ecart;
                if(Tableau[J] < Tableau[I]) {
                    Temporaire = Tableau[I];
                    Tableau[I] = Tableau[J];
                    Tableau[J] = Temporaire;
                    Inversion = 1;
                }
            }
        } while (1 == Inversion);
    } while (1 != ecart);

    printf("\nAprès:");
    for(L = 0; L < MaxTableau; L++) {
        printf(", %i",Tableau[L]);
    }
    printf("\n");
    return 0;
}
