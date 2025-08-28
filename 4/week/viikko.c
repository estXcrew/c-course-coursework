#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#ifdef LIVE
#include <locale.h>  /* Ympäristön asetuksessa käytettävä funktio setlocale. */
#include <stdlib.h>

#include "viikko.h"

int main(int argc, char *argv[])
{
  (void) argc;
  viikko(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  setlocale(LC_TIME, "fi_FI.utf8");  /* Käyttöön suomenkieli UTF8-koodauksella. */
  viikko(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  return 0;
}
#endif

int days_in_month(int year, int month) {
    /* month: 0–11 */
    static const int mdays[12] =
        {31,28,31,30,31,30,31,31,30,31,30,31};
    int d = mdays[month];

    /* leap year correction for February */
    if (month == 1) {
        if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
            d = 29;
    }
    return d;
}

void viikko(int pv, int kk, int vuosi) {
    struct tm tm;
    struct tm *tm_autogen;
    time_t timestamp;
    char buffer[30];

    int i;
    
    memset(&tm, 0, sizeof(struct tm));

    tm.tm_year = vuosi-1900;
    tm.tm_mday = pv;
    tm.tm_mon = kk-1;

    timestamp = mktime(&tm);

    /*printf("input date: %s", asctime(&tm));*/

    tm_autogen = localtime(&timestamp);

    /*printf("autogen: wday: %d\n", tm_autogen->tm_wday);*/
    

    for (i = 0; i < ((tm_autogen->tm_wday)-1); i++) {
        tm.tm_mday--;      /* step back one day */
        mktime(&tm);       /* normalize month/year change */
    }

    for(i=0; i<7; i++) {
        strftime(buffer, sizeof(buffer), "%A %d. %B %Y", &tm);
        printf("%s\n", buffer);
        tm.tm_mday++;      /* step forward one day */
        mktime(&tm);       /* normalize month/year change */
    }

}
