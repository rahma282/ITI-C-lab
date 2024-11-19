#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

int main()
{
    int n =0;
    printf("input size of magic box(odd only): ");
    scanf(" %d" ,&n);
    if (n %2 ==0){
      printf("invalid size please input odd numbers only: ");
        return 1; // out of the program
      }
      int curRow =1 , curCol=(n+1)/2;
      int totalN = n*n;

      for(int i=1; i<=totalN; i++){
            if (i==1){
                curRow =0;

            }

        if (i % n !=0){
            //decrement row -1 and col -1;              *   *   *
         curRow= curRow--;      //                      *   *   *
         curCol = curCol--;         //                  *   *   *
         if(curRow < 1)
            curRow=n;
         if(curCol < 1)
            curCol=n;
        }
      else {
          //cur %n ==0 //increment row +1
      curRow++;
      if(curRow > n)
        curRow=1;
      }
     for (int i = 0; i < n*n; i++)
    {
        for (int j = 0; j < n *n; j++)
        {printf("%d" , i);
     printf("\n");
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
     return 0;
}
