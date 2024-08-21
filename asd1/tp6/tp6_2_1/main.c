#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct date{
int year;
int month;
int day;
}date;



bool compdate(date tab[],int n){
    if(tab[n].year>tab[n+1].year){return true;}
    else if(tab[n].year==tab[n+1].year && tab[n].month > tab[n+1].month){return true;}
    else if(tab[n].year==tab[n+1].year && tab[n].month==tab[n+1].month && tab[n].day > tab[n+1].day){return true;}
    else {return false;}}

void main()
{

    date datee[10];

    for(int i=0;i<10;i++){
        printf("veuillez saisire la date numero %d : ",i+1);
        do{
        scanf("%d %d %d",&datee[i].year,&datee[i].month,&datee[i].day);
        }while(datee[i].year>12 && datee[i].month>12 && datee[i].day>31 );
    }


      int ech;
  do{ ech=0;
        for(int i=0;i<10-1;i++){

            if(compdate(datee,i)){
                int tmp;
                tmp=datee[i].year;
                datee[i].year=datee[i+1].year;
                datee[i+1].year=tmp;

                 tmp=datee[i].month;
                datee[i].month=datee[i+1].month;
                datee[i+1].month=tmp;

                 tmp=datee[i].day;
                datee[i].day=datee[i+1].day;
                datee[i+1].day=tmp;
                ech++;
            }

        }
  }while(ech>0);

  for (int i=0;i<10;i++){
  printf("%d/%d/%d \n",datee[i].year,datee[i].month,datee[i].day);

  }



}
