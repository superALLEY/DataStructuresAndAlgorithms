#include <stdio.h>
#include <stdlib.h>
/***************************************/
int fonc(){
int fonc[1000];
int c=0,nbr,somme=0;
float M=0;

         printf("veuillez saisir le nombre des elements : ");
            scanf("%d ",&nbr);
          /***************************************/
          /***************************************/
            for(int i=0;i<nbr;i++){
               printf("veuillez saisir l'elements num  %d : ",i+1);
               scanf(" \n%d\n",&fonc[i]);

            }


        for(int i=0;i<nbr;i++){



        if(fonc[i]%2==0){
             somme=somme+fonc[i];}
        else{M=M+fonc[i];
            c=c+1;}




        }
M=M/c;
printf("la sommes des nombres pairs est %d\nla moyenne des nombres impairs est %f",somme,M);


return somme;
}

/***************************************/
int main()
{
fonc();
return 0;
}
