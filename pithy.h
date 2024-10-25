#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "env.h"
 
#define BSIZE 256

int pithy(void)  {
    FILE *fp;
    char buffer[BSIZE];
    char *line;

    fp = fopen(filename, "r");

    if ( !fp ) {
        fprintf(stderr, "Unable to open the file %s!\n", filename);
        return 1;
    }

    char lines[50][BSIZE];
    int counter = 0;

    while ( !feof(fp) ) {
        line = fgets(buffer, BSIZE, fp );
        
        if ( line==NULL) {
            break;
        }

        strcpy(lines[counter], line);
        counter++;
    }

    fclose(fp);

    counter = 0;
    char temp[BSIZE];

    while (true) {
        printf("Counter is %i\n", counter);
        strcpy(temp, lines[counter]);
        if (temp[0] == '\0') {
            break;
        }
        printf("%s", temp);
        counter++;
    } 

    return 0;
}