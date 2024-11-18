#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n =0;
    printf("input size of magic box(odd only): ");
    scanf(" %d" ,&n);
    if (n %2 ==0){
      printf("invalid size please input odd numbers only: ");
        return 1; // out of the program
      }
      int curRow =0 , curCol=n/2;
      int totalN = n*n;

      for (int i=1; i<=totalN; i++){
        if (i ==1){
        //put a 1 in the middle of the first row
        curRow=0;
        curCol = 1;
      }
      else if (i % n !=0){
            //decrement row -1 and col -1;
         curRow= (curRow -1 + n) %n;
         curCol = (curCol -1 +n )%n;
      }
      else {
          //cur %n ==0 //increment row +1
      curRow = (curRow +1 )%n;
      }
      return 0;
}
}
