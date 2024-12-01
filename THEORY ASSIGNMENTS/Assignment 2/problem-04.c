/*
Name: syed Nadir Shah
ID:24k-0011
Des: identify and group "scrambled" transactions together
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_LEN 50

void sortString(char* str) {
	int i, j;
    int len = strlen(str);
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int isAnagram(const char* str1, const char* str2) {
    char sorted1[MAX_LEN], sorted2[MAX_LEN];
    strcpy(sorted1, str1);
    strcpy(sorted2, str2);
    sortString(sorted1);
    sortString(sorted2);
    return strcmp(sorted1, sorted2) == 0;
}

void groupAnagrams(const char* transactions[], int n) {
    int grouped[MAX_WORDS] = {0}; // To track which words are already grouped
	int i, j;
    for (i = 0; i < n; i++) {
        if (grouped[i]) continue;
        printf("[");
        printf("\"%s\"", transactions[i]);
        grouped[i] = 1;

        for (j = i + 1; j < n; j++) {
            if (!grouped[j] && isAnagram(transactions[i], transactions[j])) {
                printf(", \"%s\"", transactions[j]);
                grouped[j] = 1;
            }
        }
        printf("]\n");
    }
}

int main() {
    const char* transactions[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(transactions) / sizeof(transactions[0]);

    printf("Grouped Anagrams:\n");
    groupAnagrams(transactions, n);

    return 0;
}

