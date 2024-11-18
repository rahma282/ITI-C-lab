#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num =10;
    float fnum = 10.5;
    char c = 'a';
    printf(" number=%d\n float number=%f\n character =% c" , num , fnum , c);

    char c1;
    printf("Input a char: \n");
    scanf("%c" ,&c1);
    printf("c=%d\n ",c1);

    int n = 10;
    printf("hexadecimal n=%x \n",num);
    printf("octal n=%o \n" , num);

    return 0;

}
