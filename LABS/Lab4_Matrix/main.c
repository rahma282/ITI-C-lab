#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

void print();

int main() {
    int matrix[ROW][COL];
    int sumOfEveryRows = 0, sumOfCols = 0;
    int value;
    char ch;


    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Enter element [%d,%d]: ", i, j);


            while (scanf("%d%c", &value, &ch) != 2 || ch != '\n') {
                while (getchar() != '\n');  // Clear the input buffer
                printf("Invalid input! Please enter a valid integer: ");
            }
            matrix[i][j] = value;
        }
    }

    printf("\nMatrix Elements:\n");
    print();
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    print();

    // cal row sums
    for (int i = 0; i < ROW; i++) {
        sumOfEveryRows = 0;
        for (int j = 0; j < COL; j++) {
            sumOfEveryRows += matrix[i][j];
        }
        printf("Sum of row %d: %d\n", i, sumOfEveryRows);
    }
    print();

    // cal column averages
    for (int j = 0; j < COL; j++) {
        sumOfCols = 0;
        for (int i = 0; i < ROW; i++) {
            sumOfCols += matrix[i][j];
        }
        //printf("sum of col %d: %d\n",j,sumOfCols);
        printf("Average of column %d: %.2f\n", j, (float)sumOfCols / ROW);
    }

    return 0;
}

void print() {
    printf("--------------------------\n");
}
