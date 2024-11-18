#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

int main()
{
    int arr[SIZE] ={1};
    int row,col,i,j;


    for(int i=0; i<SIZE; i++)
    {
        printf("Enter element %d to the array: ",(i+1));
        scanf("%d", &arr[i]);
    }
    printf("Enter number of rows: ");
    scanf ("%d",&row);
    if(SIZE % row !=0 || row > SIZE){
        printf("Invalid input it again: ");
        return 1;
    }
    col = SIZE /row;
    for (i=0; i<row; i++){
        for (j=0; j<col; j++){
            printf("%d\t",arr[i*col +j]);
        }
        printf("\n");
    }

    return 0;
}
