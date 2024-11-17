#include <stdio.h>
#include <stdlib.h>

int getAscendingMulti()
{
    printf("Ascending order:\n");
    int num =0;
   for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            num =i*j;
            printf ("%d * %d= %d\n" , i,j,num);
        }

   }
   return 0;


}
