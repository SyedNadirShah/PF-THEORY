/*
Name: syed Nadir Shah
ID:24k-0011
Des: reducing consecutive duplicate characters to a single instance of the character
*/
#include <stdio.h>
#include <string.h>

void compressWord(const char* word, char* compressedWord, int* removedCount) {
    int i, j = 0, removed = 0;
    int length = strlen(word);

    for (i = 0; i < length; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressedWord[j++] = word[i];
        } else {
            removed++;
        }
    }

    compressedWord[j] = '\0';
    *removedCount = removed;
}

void compressWords(const char* words[], char compressedWords[][50], int numWords, int* totalRemoved) {
    int i, removed;
    *totalRemoved = 0;

    for (i = 0; i < numWords; i++) {
        compressWord(words[i], compressedWords[i], &removed);
        *totalRemoved += removed;
    }
}

int main() {
    const char* words[] = {"booooook", "coooool", "heeeey"};
    int numWords = sizeof(words) / sizeof(words[0]);
    char compressedWords[10][50];
    int i, totalRemoved;

    compressWords(words, compressedWords, numWords, &totalRemoved);

    printf("Compressed Words:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s -> %s\n", words[i], compressedWords[i]);
    }

    printf("Total Characters Removed: %d\n", totalRemoved);

    return 0;
}

