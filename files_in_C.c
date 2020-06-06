#include <stdio.h>
#include <string.h>
int main(void){
    FILE *filePTR;

    filePTR = fopen("lol.txt", "w");
    // file existence check
    if(filePTR == NULL)
        perror("noooooo, file doesn't exist");
    else
        puts("hmm, your file exists for some reason");
    
    // a string to put in the file
    char *string;
    //scanf("%s", &string);
    string = "Sup cyka! ";
    int counter = 0;
    for( ; counter < strlen(string); counter++){
        // appends a character to a file
        fputc(string[counter], filePTR);
    }
    // appends a string into a file
    fputs(string, filePTR);
    
    int k = 8, m = 9;
    // appends a formatted string to a file
    fprintf(filePTR, " k = %d, m = %d ", k, m);

    // close the file when you're done with it
    fclose(filePTR);

    // reopen file in read mode
    filePTR = fopen("lol.txt", "r");
    char stored[99];
    // reads data from file into a string
    fscanf(filePTR, "%s", stored);
    printf("\nstring from file: %s\n", stored);   

    // rewind to avoid reopenning the file again :)
    rewind(filePTR);
    // feof returns false(0) if not at the end of a file
    while(!feof(filePTR)){
        // returns a charater from the file
        printf("%c", fgetc(filePTR));
    }
    // close the file when you're done with it
    fclose(filePTR);

    return 0;
}
