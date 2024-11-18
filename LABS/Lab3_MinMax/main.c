#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    int arr[SIZE] ={1};
    int size;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter elements in the array: ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[size-1];


    for(int i=1; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("max element = %d\n", max);
    printf("min element = %d", min);

    return 0;
}
