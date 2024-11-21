#include <stdio.h>
#include <stdlib.h>
#include "strinFunctions.h"

#define TERMINATOR '\0'

int StringLength(char str[]) {
    int length = 0;

    while (str[length] != TERMINATOR) {
        length++;
    }
    return length;
}
void StringConcat(char dest[], char source[]){
    int i=0;
    int j=0;
    while (dest[i] != TERMINATOR){
        i++;
    }
    while (source[j] != TERMINATOR){
        dest[i]=source[j];
        i++;
        j++;
    }
    dest[i] =TERMINATOR;
}
