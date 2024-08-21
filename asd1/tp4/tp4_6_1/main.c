#include <stdio.h>
#include <stdlib.h>





float fonc(int m){

    float b;
if (m==1){return -0.5;}
else { b=fonc(m-1);
 float k ;;
if(m%2==0){k=1;}else{k=-1;}


    return b+(k/(2*m));
}
}



int main()
{int x;
float c;
 scanf("%d",&x);
 c=fonc(x);
 printf("%f",c);
    return 0;
}

