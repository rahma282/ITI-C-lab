#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

int main()
{
     int n =0;

    int curRow, curCol;

    printf("input size of magic box(odd only): ");
    scanf(" %d" ,&n);

    if (n %2 ==0){
      printf("invalid size please input odd numbers only: ");
        return 1; // out of the program
    }
    else{
      curRow =1 , curCol=(n+1)/2;
      gotoxy(curRow*3, curCol*4);
      printf("1");
}

      for (int i=2; i<n*n; i++){

        if ((i-1) % n !=0){
            //decrement row -1 and col -1;     *   *   *
         curRow--;      //                     *   *   *
         curCol--;           //                *   *   *
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
        gotoxy(curRow*3, curCol*4);
            sleep(2);
            printf("%d", i);
    }
          return 0;

}
