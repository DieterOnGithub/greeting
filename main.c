#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])  {
    if (argc<2) {
        printf("Hello, you coding genius!\n");
    }
    else {
        printf("Hello %s!\n", argv[1]);
    }

    time_t now;
    struct tm *clock;
    int hour;
    
    time(&now);
    clock = localtime(&now);
    printf("The current time is %s", asctime(clock));

    hour = clock->tm_hour;
    if (hour<8) {
        printf("We are up really early today!\n");
    }
    else if (hour<16) {
        printf("This time of day feels normal to us, right?\n");
    }
    else {
        printf("We are really pushing hard today, aren't we?\n");
    } 

    return 0;
}