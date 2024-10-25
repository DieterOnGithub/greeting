#include <stdio.h>
#include <time.h>
#include "moonlighting.h"
#include "pithy.h"

int main(int argc, char *argv[])  {
    if (argc<2) {
        printf("Hello, you coding genius!\n");
    }
    else {
        printf("Hello %s!\n", argv[1]);
    }

    print_moon();
    pithy();

    return 0;
}