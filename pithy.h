#include <stdio.h>
#include <stdlib.h>
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

    while ( !feof(fp) ) {
        line = fgets(buffer, BSIZE, fp );
        if ( line==NULL) {
            break;
        }
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}