#include <stdio.h>
#include <stdlib.h>
#include "strinFunctions.h"
//int StringLength(char str[]);
//void StringConcat(char dest[], char source[]);

int main() {

    char str[20]="rahma";

    int len = StringLength(str);
    printf("%d\n", len);

    char source[10]=" mostafa";
    StringConcat(str,source);
    printf("%s\n",str);

    return 0;
}
/*
int StringLength(char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}
*//*
void StringConcat(char dest[], char source[]){
    int i=0; //rahma
    int j=0; //mostafa
    while (dest[i] !='\0'){
        i++;
    }
    while (source[j] !='\0'){
        dest[i]=source[j];
        i++;
        j++;
    }
    dest[i] ='\0';
}
*/
