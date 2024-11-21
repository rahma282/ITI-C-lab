#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
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
=======
#include "stringFunctions.h"

#define TERMINATOR '\0'
#define DESTSIZE 25
int main() {

    char str[20]="RAhma";
    char source[10]=" mostafa";
    char dest [DESTSIZE] ="sara";

    int len = StringLength(str);
    printf("length = %d\n", len);

    StringConcat(str,source);
    printf("%s\n",str);

    toLower(str);
    printf("stringlowercase: ");
    printf("%s\n", str);


    toUpper(str);
    printf("stringuppercase: ");
    printf("%s\n", source);

    printf("Before Copy dest = %s\n",dest);
    StringCopy(dest,source,DESTSIZE);
    printf("After Copy dest = %s\n",dest);

    char s1[20] = "help";
    char s2[20] = "help";

    // function call
    compareString(s1, s2);

    return 0;
}

int StringLength(char str[]) {
    int length = 0;

    while (str[length] != TERMINATOR) {
>>>>>>> ed986b0 (update DBMenu)
        length++;
    }
    return length;
}
<<<<<<< HEAD
*//*
void StringConcat(char dest[], char source[]){
    int i=0; //rahma
    int j=0; //mostafa
    while (dest[i] !='\0'){
        i++;
    }
    while (source[j] !='\0'){
=======
//concat function
void StringConcat(char dest[], char source[]){
    int i=0;
    int j=0;
    while (dest[i] != TERMINATOR){
        i++;
    }
    while (source[j] != TERMINATOR){
>>>>>>> ed986b0 (update DBMenu)
        dest[i]=source[j];
        i++;
        j++;
    }
<<<<<<< HEAD
    dest[i] ='\0';
}
*/
=======
    dest[i] =TERMINATOR;
}
//toLower
void toLower(char str[]){
    int i=0;
    while (str[i] != TERMINATOR){
        if (str[i] >= 'A' && str[i] <= 'Z'){   // if it uppercase
            str[i]+=32;
        }
        i++;
    }
}
//toUpper
void toUpper(char str[]){
    int i=0;
    while (str[i] != TERMINATOR){
        if (str[i]>='a' && str[i]<='z'){   // if it uppercase
            str[i]-=32;
        }
        i++;
    }
}
//copyString
void StringCopy(char dest[],char source[],int size ){
    int i=0;
    if(StringLength(source)<= size-1){
        printf("Valid Size \n");
        while(source[i] != TERMINATOR){
            dest[i]=source[i];
            i++;
        }
        dest[i]='\0';
    }
    else {
        printf("error: source is larger than destination size\n");
    }
}
int compareString(char str[] ,char str2[]){
   int strLength = StringLength(str);
   int str2Length =StringLength(str2);
   while (str[strLength] != '\0')
		strLength ++;

	while (str2[str2Length] != '\0')
		str2Length ++;

    int	i = 0;

	while (str[i] == str2[i] && str[i] != '\0')
	{
		i ++;
	}

	if (str[i] > str2[i])
		printf ("First string is greater than Second string\n");
	else if (str[i] < str2[i])
		printf("Second string is greater than First string\n");
	else
		printf ("Both strings are EQUAL\n");

	return 0;
}

>>>>>>> ed986b0 (update DBMenu)
