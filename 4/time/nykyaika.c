#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main() {
    time_t epoch_time;
    struct tm *tm_info;
    epoch_time = time(NULL);
    setlocale(LC_TIME, "fi_FI.UTF-8");
    tm_info = localtime(&epoch_time);

    if(tm_info != NULL) {
        char buffer[30];
        strftime(buffer, sizeof(buffer), "%A %d.%m.%Y klo %H:%M", tm_info);
        buffer[0] = toupper(buffer[0]);
        printf("%s\n", buffer);
    }

    return 0;
}