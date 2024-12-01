/*
Name: syed Nadir Shah
ID:24k-0011
Des: analyze the character frequency in the list of slogans
*/
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void analyzeFrequency(const char* slogan) {
    int frequency[MAX_CHAR] = {0};
    int i;

    for (i = 0; slogan[i] != '\0'; i++) {
        frequency[(int)slogan[i]]++;
    }

    printf("Character Frequency for \"%s\":\n", slogan);
    for (i = 0; i < MAX_CHAR; i++) {
        if (frequency[i] > 0) {
            printf("'%c': %d\n", i, frequency[i]);
        }
    }
}

int main() {
    const char* slogans[] = {"buy now", "save big", "limited offer"};
    int n = sizeof(slogans) / sizeof(slogans[0]);
    int i;

    for (i = 0; i < n; i++) {
        analyzeFrequency(slogans[i]);
        printf("\n");
    }

    return 0;
}

