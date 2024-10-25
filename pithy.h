#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "env.h"
 
#define BSIZE 256

int pithy(void)  {
    // set up variables to read in pithy text file
    FILE *fp;
    char buffer[BSIZE];
    char *line;

    fp = fopen(filename, "r");

    // generate error message if file reading not possible and exit program
    if ( !fp ) {
        fprintf(stderr, "Unable to open the file %s!\n", filename);
        return 1;
    }

    // initialize array of 50 strings of size BSIZE to store the lines of the file in
    char lines[50][BSIZE];
    int counter = 0;

    while ( !feof(fp) ) {
        line = fgets(buffer, BSIZE, fp );
        
        // stop reading when no more file lines left
        if ( line==NULL) {
            break;
        }

        // add current file line as new element to array
        strcpy(lines[counter], line);
        counter++;
    }

    fclose(fp);

    // seed rand function with current time
    srand(time(NULL));

    // generate random number to pick line/string from array
    int index = rand() % (counter + 1);

    // print out line from array
    printf("Wise line for today: %s", lines[index]);

    return 0;
}