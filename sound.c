#include <stdio.h>

void gregorianToHijri(int gYear, int gMonth, int gDay, int *hYear, int *hMonth, int *hDay) {
    // Umm al-Qura algorithm
    int julianDay, daysCount, daysDifference;

    // Calculate Julian day number
    julianDay = gDay - 32075 +
                1461 * (gYear + 4800 + (gMonth - 14) / 12) / 4 +
                367 * (gMonth - 2 - (gMonth - 14) / 12 * 12) / 12 -
                3 * ((gYear + 4900 + (gMonth - 14) / 12) / 100) / 4;

    // Calculate days difference between the Gregorian and Hijri calendars
    daysDifference = julianDay - 1948440 - 1;

    // Calculate Hijri year
    *hYear = 1356 + daysDifference / 354;

    // Calculate remaining days
    daysCount = daysDifference % 354;

    // Calculate Hijri month and day
    int i;
    for (i = 1; i <= 12; i++) {
        int daysInMonth = 29 + ((i + 1) % 2) + ((i >= 7) ? ((i == 12 && (*hYear % 4 == 2)) ? 1 : 0) : 0);
        if (daysCount < daysInMonth) {
            break;
        }
        daysCount -= daysInMonth;
    }

    *hMonth = i;
    *hDay = daysCount + 1;
}

int main() {
    // Example Gregorian date (replace with your actual values)
    int gregorianYear = 2023;
    int gregorianMonth = 12;
    int gregorianDay = 24;

    // Variables to store the converted Hijri date
    int hijriYear, hijriMonth, hijriDay;

    // Call the conversion function
    gregorianToHijri(gregorianYear, gregorianMonth, gregorianDay, &hijriYear, &hijriMonth, &hijriDay);

    // Print the result
    printf("Gregorian: %d-%02d-%02d\n", gregorianYear, gregorianMonth, gregorianDay);
    printf("Hijri: %d-%02d-%02d\n", hijriYear, hijriMonth, hijriDay);

    return 0;
}