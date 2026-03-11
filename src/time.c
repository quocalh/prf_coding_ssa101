#include <time.h>
#include "../include/time.h"


void FetchTime(CurrentTime* Time)
{   
    time_t rawTime;
    time(&rawTime);
    struct tm* localTime;
    localTime = localtime(&rawTime);

    Time -> year = localTime -> tm_year + 1900;
    Time -> month = localTime -> tm_mon + 1;
    Time -> date = localTime -> tm_mday;

    Time -> sec = localTime -> tm_sec;
    Time -> min = localTime -> tm_min;
    Time -> hour = localTime -> tm_hour;
}
