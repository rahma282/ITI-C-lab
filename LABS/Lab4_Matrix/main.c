#include <stdio.h>
#include <stdlib.h>
void print();

int main()
{
    int row = 3, col = 4,sumOfEveryRows=0,sumOfCols=0;
    int value;
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
    for (int j = 0; j < col; j++)
        {
             printf("Enter element [%d,%d]: ", i, j);
             while (scanf("%d", &value) != 1) {
                // Clear the input buffer of any invalid data
                while (getchar() != '\n');
                printf("Invalid input! Please enter a valid integer: ");
            }
            matrix[i][j] = value;
        }
    }
        printf("\n");

    print();

    for (int i = 0; i < row; i++)
    {
    for (int j = 0; j < col; j++)
        {
             printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
   print();

    for (int i = 0; i < row; i++)
    {
        sumOfEveryRows=0;
        for (int j = 0; j < col; j++)
        {
            sumOfEveryRows+=matrix[i][j];  //sum of every rows
    }
        printf("sum of row %d: %d\n",i,sumOfEveryRows);
        print();
    }
    for (int j=0; j<col; j++){
            sumOfCols=0;
        for (int i=0; i<row; i++){
            sumOfCols+=matrix[i][j];  //sum of columns

        }
        //printf("sum of col %d: %d\n",j,sumOfCols);
        printf("average of each column %d\n",sumOfCols/row);  //average of cols
    }

    return 0;
}

void print (){
    printf("--------------------------\n");
}
