#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n =0, sum =0, vaildInput;

    printf("enter number: ");
    while (1){
    vaildInput =scanf("%d",&n);
    if (vaildInput !=1){
        printf("invalid input , please input valid integer:\n ");
        while (getchar() != '\n'); // Clear the input buffer
    }
    else if (vaildInput < 0){
        printf("invalid input , please input positive integer only:\n ");
    }
    else{
        sum += n;
    }
    if (sum >100){
        printf("sum exceeded 100! Final sum: %d\n", sum);
        return;
    }
    printf("%d\n",sum);
    }


    return 0;
}
