#include <stdio.h>
#include <stdlib.h>

int pow (int num,int pow);
int main()
{
    int num ,pow, result ;
    pow =num =result =0;
    printf ("enter a number to calculate it's power: ");
    scanf(" %d",&num);
    printf ("enter number's power: ");
    scanf(" %d",&pow);

    result = power(num, pow);
    printf("%d ^ %d = %d", num,pow,result);
    return 0;
}
int power(int num, int pow){
    if (num<0){
        return -1;
    }
    if (pow){
        return (num * power(num , pow -1));
    }
    return 1;

}
