#include <stdio.h>
#include <stdlib.h>
void swap1(int *num1, int *num2);
void swap2(int *num3, int *num4);

int main()
{
    int num1 =10 ,num2 =15,num3 =11,num4=21;
    printf("Num1 before swaping %d\n",num1);
    printf("Num1 before swaping %d\n",num2);
    swap1(&num1,&num2);
    printf("Num1 after swapping: %d\n", num1);
    printf("Num2 after swapping: %d\n", num2);

    printf("Num1 before swaping %d\n",num3);
    printf("Num1 before swaping %d\n",num4);
    swap2(&num3, &num4);
    printf("Num3 after swapping: %d\n", num3);
    printf("Num4 after swapping: %d\n", num4);
    return 0;
}
void swap1(int *num1, int *num2){
    *num1 = *num1 - *num2;
    *num2 = *num2 + *num1;
    *num1 = *num2 - *num1;
}
void swap2(int *num3, int *num4){
 if (*num4 != 0) {
    *num3 = *num3 * *num4;
    *num4 = *num3 / *num4;
    *num3 = *num3 / *num4;
    }
    else{
    printf("Error Devision by zero");
    }
}
