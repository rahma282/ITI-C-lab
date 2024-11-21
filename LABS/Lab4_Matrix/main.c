#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4
void print();

int main()
{
    int sumOfEveryRows=0,sumOfCols=0;
    int value;
    char ch;
    int matrix[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
    for (int j = 0; j < COL; j++)
        {
             printf("Enter element [%d,%d]: ", i, j);

                 while (scanf("%d%c", &value, &ch) != 2 || ch != '\n') {
                // Clear the input buffer of any invalid data
                while (getchar() != '\n');
                printf("Invalid input! Please enter a valid integer: ");
            }
            matrix[i][j] = value;
        }

    }
        printf("\n");

    print();

    for (int i = 0; i < ROW; i++)
    {
    for (int j = 0; j < COL; j++)
        {
             printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
   print();

    for (int i = 0; i < ROW; i++)
    {
        sumOfEveryRows=0;
        for (int j = 0; j < COL; j++)
        {
            sumOfEveryRows+=matrix[i][j];  //sum of every rows
    }
        printf("sum of row %d: %d\n",i,sumOfEveryRows);
        print();
    }
    for (int j=0; j<COL; j++){
            sumOfCols=0;
        for (int i=0; i<ROW; i++){
            sumOfCols+=matrix[i][j];  //sum of columns

        }
        //printf("sum of col %d: %d\n",j,sumOfCols);
        printf("average of column %d:%d\n",j,sumOfCols/ROW);  //average of cols
    }

    return 0;
}

void print (){
    printf("--------------------------\n");
}
