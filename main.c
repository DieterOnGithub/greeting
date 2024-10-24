#include <stdio.h>
#include <time.h>

int moonlighting(int year,int month,int day) {
    int d,g,e;
 
    d = day;
    if(month == 2)
        d += 31;
    else if(month > 2)
        d += 59+(month-3)*30.6+0.5;
    g = (year-1900)%19;
    e = (11*g + 29) % 30;
    if(e == 25 || e == 24)
        ++e;
    return ((((e + d)*6+5)%177)/22 & 7);
}

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

    int year, month, day;
    year = clock->tm_year;
    month = clock->tm_mon;
    day = clock->tm_mday;

    char *phase[8] = {
        "waxing crescent", "at first quarter",
        "waxing gibbous", "full", "waning gibbous",
        "at last quarter", "waning crescent", "new"
    };

    int moon = moonlighting(year, month, day);
    printf("The current moon phase is '%s'!\n", phase[moon]);

    return 0;
}