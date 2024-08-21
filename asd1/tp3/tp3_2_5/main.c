#include<stdio.h>

void main()
{
    int i,j,n,k;
    printf("Enter the no of lines of * to be printed\n");
    scanf("%d", &n);
 k=1;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            printf(" ");
        }
         for(j=1;j<=i;j++)
        {
            printf("%d ",k);k=k+1;
        }
        printf("\n");
    }
}
