#ifndef AUXFUNCTIONS_H
#define AUXFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// necessary for some reason :)
void hold(){
    puts("\n\tpress enter to continue....");
    // getchar is used to input a character
    while(getchar() != '\n');
}

// cross platform clear screen
void clear(){
    int counter = 0;
    while(counter < 100){
        puts("\n");
        counter++;
    }
}

// welcome screen
void welcome(){
    clear();
    puts("\n\tTerminal notes taking program!!\n");
    puts("\tBy Baraa Al-Masri . version 0.001");
    hold();
    clear();
}

// menu
int menu(){
    clear();
    listDir(".");
    puts("\n----------------------");
    puts("Available actions:");
    puts("1. Add a new note");
    puts("2. Add to existing note");
    puts("3. Delete note");
    puts("4. View a note");
    puts("5. Exit");
    printf("\nenter a choice:  ");
    int choice;
    scanf("%d", &choice);

    return choice;
}

// 
void quit(){
    puts(RED);
    puts("have a nice day!");
    puts(RESET);
    exit(0);
}

// action taker
void actionChooser(){
    while(1){
        int choice = menu();
        

        void  (*functions[])(char noteName[99]) = {&addNote, &addToNote, &deleteNote, &viewNote};

        if(choice < 5){
            printf("\nenter note name:  ");
            char noteName[99];
            scanf("%s", &noteName);
            functions[choice - 1](noteName);
        }
        else if(choice == 5)
            quit();
        else
            continue;
        // for some fucking reason I had to put the loop after the function call :(
        hold();
        while(getchar() != '\n');
    }
}

#endif // AUXFUNCTIONS