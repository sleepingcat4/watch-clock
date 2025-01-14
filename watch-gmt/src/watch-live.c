#include <stdio.h>
#include <time.h>
#include <unistd.h>

const char* get_suffix(int day) {
    if (day >= 11 && day <= 13) return "th";
    switch (day % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

void current_time() {
    time_t rawtime;
    struct tm *timeinfo;
    int second_counter = 0;

    printf("Monday 14th, 2025. Current time: 15:30:45 GMT");

    while (1) {
        time(&rawtime);
        timeinfo = gmtime(&rawtime);

        char formatted_date[100];
        strftime(formatted_date, sizeof(formatted_date), "%A", timeinfo);

        printf("\r%s %d%s, %d. Current time: %02d:%02d:%02d GMT", 
            formatted_date, timeinfo->tm_mday, get_suffix(timeinfo->tm_mday), 
            1900 + timeinfo->tm_year, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

        fflush(stdout);
        sleep(1);
    }
}

int main() {
    current_time();
    return 0;
}
