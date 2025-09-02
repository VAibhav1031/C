#include "stdio.h"
#include "stdlib.h"  // For system()
#include "time.h"
#include "unistd.h"

void filltime(char*, int);
void fill_date(char*);
void clear_screen();
int input_format();

int main() {
    char time_[50], date_[100];
    int format = input_format();

    while (1) {
        filltime(time_, format);
        fill_date(date_);
        clear_screen();
        printf("Current Time: %s\n", time_);
        printf("Date: %s\n", date_);
        sleep(1);
    }
    return 0; 
}

int input_format() {
    int input;
    printf("\n\nChoose Format:\n");
    printf("1. 12-Hour Format\n");
    printf("2. 24-Hour Format\n");
    scanf("%d", &input);
    return input;
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux/Unix/macOS
    #endif
}

void filltime(char* formatted_time, int format) {
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    if (format == 1) {
        // 12-hour format
        int hour = local_time->tm_hour;
        char *am_pm = (hour >= 12) ? "PM" : "AM"; //ternay operator 
        hour = (hour % 12 == 0) ? 12 : hour % 12;  // Convert to 12-hour format
        snprintf(formatted_time, 50, "%02d:%02d:%02d %s", hour, local_time->tm_min, local_time->tm_sec, am_pm);
        //we  are basically using the  local_time pointer and using all the adress to it like tm_sec or min
    } else {
        // 24-hour format
        snprintf(formatted_time, 50, "%02d:%02d:%02d", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
    }
}

void fill_date(char* formatted_date) {
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    snprintf(formatted_date, 100, "%02d-%02d-%04d", 
             local_time->tm_mday, 
             local_time->tm_mon + 1,  // tm_mon is 0-indexed, so add 1
             local_time->tm_year + 1900);  // tm_year is years since 1900
}

