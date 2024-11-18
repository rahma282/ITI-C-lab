#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = 0;
   printf("Input a choice of a to c: ");
   scanf(" %c", &ch);
   switch (ch){
        case 'a':
            printf("your choice is 1 \n");
            break;
        case 'b':
            printf("your choice is 2 \n");
            break;
        case 'c':
            printf("your choice is 3 \n");
            break;
        default:
            printf("not valid \n");
   }
}
