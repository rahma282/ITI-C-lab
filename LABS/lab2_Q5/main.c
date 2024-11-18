#include <stdio.h>
#include <stdlib.h>

int main()
{
     int num =0;
    printf("Descending order:\n");
   for (int i=10; i>=1; i--){
        for (int j=10; j>=1; j--){
            num =i*j;
            printf ("%d * %d= %d\n" , i,j,num);
        }

   }
   return 0;


}
