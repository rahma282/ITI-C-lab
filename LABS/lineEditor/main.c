#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <unistd.h>
#include <time.h>
#include "mina.h"

#define RIGHT 67 //move the cursor right one by one
#define LEFT  68  //move the cursor left one by one
#define UP 65 //first click stand into char ,second click overwrite  (input up arrow) insert
#define DELETE 66 //delete after cursor  (input down arrow)
#define BACKSPACE 127  //delete before cursor
#define HOME 72 //go to first line
#define END 70   //go to left line
#define ENTER 10      //exit   (input enter)
#define SIZE 100   //size of array
#define TERMINATOR '\0'

typedef struct linePtr{
    int *current=NULL;
    int *head =NULL;
    int *tail =NULL;

}linePtr;

char line[SIZE]={0};

//functions prototype
int getInput();
void displayLine(linePtr *ptr);
void moveCursorLeft(linePtr *ptr);    //move to left (left--)
void moveCursorRight(linePtr *ptr);  //move to right (right++)
void insert(linePtr *ptr,char ch);   //first click stand into char ,second click overwrite
void deleteCharBeforCursor(linePtr *ptr);   //backspce
void deleteCharAfterCursor(linePtr *ptr);   //del
void moveCursorToHome(linePtr *ptr);        //go to begain of the line =head(0)
void MoveCursorToend(linePtr *ptr);        //go to the end of the line =tail (SIZE -1)

int main(){
linePtr ptr = { .current =line, .head=line, .tail=line};
char ch_in;

while (1) {
    displayLine(&ptr);
    ch_in = getInput();
    printf("Received input: %d\n", ch);
    fflush(stdout);
    switch (ch_in) {
        case RIGHT:
            moveCursorRight(&ptr);
            break;
        case LEFT:
            moveCursorLeft(&ptr);
            break;
        case HOME:
            moveCursorToHome(&ptr);
            break;
        case END:
            MoveCursorToend(&ptr);
            break;
        case DELETE:
            deleteCharAfterCursor(&ptr);
            break;
        case UP:
            insert(&ptr, ch_in);
            break;
        case BACKSPACE:
            deleteCharBeforCursor(&ptr);
            break;
        case ENTER:
            return 0;  // Exit
        default:  // input normal char
            if (ptr.tail < line + SIZE - 1) {
                insert(&ptr, ch_in);
            }
            break;
    }
}
return 0;
}

int getInput(){
    char ch = getch();
    printf("Received input: %d\n", ch);
    fflush(stdout);
    if (ch == 27) {
        if (getch() == '[') {
            ch = getch();  // get extended key
            printf("Extended key: %d\n", ch);
            fflush(stdout);
            return ch;
        }
        return 27;
    }
    return ch;  //normal key
}

void displayLine(linePtr *ptr){
    system("clear");
    for (int cursor = 0; cursor < SIZE; cursor++)
    {
        if (cursor == ptr->current)
        {
            setTextColor(stdout, TC_RED);
            printf("%c", line[cursor]);
        }
        else
        {
            setTextColor(stdout, TC_WHITE);
            printf("%c", line[cursor]);
        }
    }
    fflush(stdout);
}

void moveCursorLeft(linePtr *ptr){
    if (ptr->current > ptr->head){
        ptr->current--;
    }
}

void moveCursorRight(linePtr *ptr){
    if (ptr->current < ptr->tail ){
        ptr->current++;
    }
}

void deleteCharBeforCursor(linePtr *ptr){
    if (ptr->current > ptr->head) {
        ptr->current--; //move cursor before char then delete
        // shift characters from the current to the left
        for (int i = ptr->current; i < ptr->tail - 1; i++) {
            line[i] = line[i + 1];
        }
        line[ptr->tail - 1] = TERMINATOR;
        // move the tail pointer back
        ptr->tail--;
    }
}
void deleteCharAfterCursor(linePtr *ptr){
    if (ptr->current < ptr->tail) {
        // shift characters from the current position + 1 to the end of the line
        for (int i = ptr->current; i < ptr->tail - 1; i++) {
            line[i] = line[i + 1];
        }
        line[ptr->tail - 1] =TERMINATOR;
        // decrease the tail to remove the character at current
        ptr->tail--;
    }
}
void insert(linePtr *ptr,char ch){             //first click stand into char ,if input any char overwrite curent char
     if (ptr->tail < line + SIZE - 1) {  // if there space in the array
        if (ptr->current < ptr->tail) {
            line[ptr->current] = ch;  // overwrite current character
        } else {
            line[ptr->current] = ch;
            ptr->tail++;
        }
        ptr->current++;
    }
}
void moveCursorToHome(linePtr *ptr){
    ptr->current = ptr->head;
}
void MoveCursorToend(linePtr *ptr){
    ptr->current = ptr->tail;
}



