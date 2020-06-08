#ifndef ACTIONS_H
#define ACTIONS_H

#include <dirent.h>
#include <string.h>
#include <stdio.h>

// list files in current directory
void listDir(char *directoryName){
    puts("Available files:\n");
    struct dirent *directoryEntry;  // Pointer for directory entry 
    // opendir() returns a pointer of DIR type.  
    DIR *directoryPtr = opendir(directoryName); 
    // opendir returns NULL if couldn't open directory
    if (directoryPtr == NULL){ 
        printf("Could not open current directory" ); 
        return; 
    } 
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
    while ((directoryEntry = readdir(directoryPtr)) != NULL)
        if( directoryEntry->d_name[0] != '.' ) 
            printf("%s\n", directoryEntry->d_name); 
    // close directory after being done with it
    closedir(directoryPtr); 
}

// view an existing note
void viewNote(char noteName[99]){
    FILE *noteFile;
    // open file in read mode to see the current note
    noteFile = fopen(noteName, "r");
    
    while(!feof(noteFile)){
        printf("%c", fgetc(noteFile));
    }
    fclose(noteFile);
}

// add to existing note
void addToNote(char noteName[99]){
    FILE *noteFile;
    
    viewNote(noteName); 
    // reopen file in append mode
    noteFile = fopen(noteName, "a");
    puts("\nenter your note type 'qq' when you are done(type '\\n' to jump a line)");
    char note[99];
    while(1){
        scanf("%s", &note);
        if(note[0] == 'q' && note[1] == 'q')
            break;
        // if there's a return escape sequence
        if(note[0] == '\\' && (note[1] == 'n' || note[1] == 'r') ){
            fputc('\n', noteFile);
        }
                                            
        else{    
            // append a space to the string for better formatting in the file
            strcat(note, " ");
            fputs(note, noteFile);
        }
    }

    fclose(noteFile);
}

// create new note
void addNote(char noteName[99]){
    FILE *noteFile;
    noteFile = fopen(noteName, "w");
    addToNote(noteName);
}

// delete a note
void deleteNote(char noteName[99]){
    remove(noteName);
}

#endif // ACTION_H