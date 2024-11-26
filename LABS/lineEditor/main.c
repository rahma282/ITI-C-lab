#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <unistd.h>
#include <time.h>
#include "mina.h"

#define RIGHT 67 //move the cursor right one by one
#define LEFT  68  //move the cursor left one by one
#define INSERT 65 //first click stand into char ,second click overwrite  (input up arrow)
#define DELETE 66 //delete after cursor  (input down arrow)
#define BACKSPACE 127  //delete before cursor
#define HOME 72 //go to first line
#define END 70   //go to left line
#define ENTER 10      //exit   (input enter)
#define SIZE 100   //size of array
#define SKIP 27
#define TERMINATOR '\0'

typedef struct linePtr{
    int current;   //current =0 then curent++
    int head ;      //head =0;
    int tail;      //tail = 0;  //size-1

}linePtr;

char line[SIZE]={0};

//functions prototype
void displayLine(linePtr *ptr);
void moveCursorLeft(linePtr *ptr);    //move to left (left--)
void moveCursorRight(linePtr *ptr);  //move to right (right++)
void insert(linePtr *ptr,char ch);   //first click stand into char ,second click overwrite
void deleteCharBeforCursor(linePtr *ptr);   //backspce
void deleteCharAfterCursor(linePtr *ptr);   //del
void moveCursorToHome(linePtr *ptr);        //go to begain of the line =head(0)
void MoveCursorToend(linePtr *ptr);        //go to the end of the line =tail (SIZE -1)

int main()
{

 linePtr ptr = { .current =0, .head=0, .tail=0};

   char ch_in;
    while (1) {
        displayLine(&ptr);
        ch_in = getch();

        if (ch_in == SKIP) {  //extended keys
            ch_in = getch();
            ch_in = getch();  // Get the second byte to identify the arrow key
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
            }
        } else if (ch_in == BACKSPACE) {  //normal keys
            deleteCharBeforCursor(&ptr);
        } else if (ch_in == ENTER) {
            return 0;  // Exit
        } else {
            insert(&ptr,ch_in);
        }
    }
    return 0;
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
        // Shift characters from the current position + 1 to the end of the line
        for (int i = ptr->current; i < ptr->tail - 1; i++) {
            line[i] = line[i + 1];
        }
        line[ptr->tail - 1] =TERMINATOR;
        // decrease the tail to remove the character at current
        ptr->tail--;
    }
}
void insert(linePtr *ptr,char ch){             //first click stand into char ,if input any char overwrite curent char
    if (ptr->tail < SIZE - 1) {
        for (int i = ptr->tail; i > ptr->current; i--) {
            line[i] = line[i - 1];  // shift characters to the right
        }
        line[ptr->current] = ch;  // insert the character at the current position
        ptr->tail++;
        line[ptr->tail] = TERMINATOR;
        ptr->current++;  // Move the cursor forward
        printf("%s" ,line);
    }
}
void moveCursorToHome(linePtr *ptr){
    ptr->current = ptr->head;
}
void MoveCursorToend(linePtr *ptr){
    ptr->current = ptr->tail;
}



