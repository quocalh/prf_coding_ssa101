#ifndef TIME_H
#define TIME_H

#include <time.h>

typedef struct {
    int month;
    int date;
    int year;

    int sec;
    int min;
    int hour;

} CurrentTime;


void FetchTime(CurrentTime *Time);

#endif