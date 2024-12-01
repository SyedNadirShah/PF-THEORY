/*
Name: syed Nadir Shah
ID:24k-0011
Des: identify and group "scrambled" transactions together
*/
/*
Name: syed Nadir Shah
ID:24k-0011
Des: manage a 6x5 2D array of characters
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 6
#define COLS 5

void generateArray(char arr[ROWS][COLS], int studentID[]) {
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j, index = 0;

    // Populate the first 5 rows with random characters
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = alpha[rand() % 26];
        }
    }

    // Populate the last row with student ID digits
    for (j = 0; j < COLS; j++) {
        if (index < 4) {
            arr[ROWS - 1][j] = studentID[index] + '0';  // Convert digit to character
            index++;
        } else {
            arr[ROWS - 1][j] = alpha[rand() % 26]; // Extra random characters
        }
    }
}

void printArray(char arr[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int searchString(char arr[ROWS][COLS], char *str) {
    char flatArray[ROWS * COLS + 1];
    int i, j, k = 0;

    // Flatten the 2D array to a 1D array
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            flatArray[k] = arr[i][j];
            k++;
        }
    }
    flatArray[k] = '\0';  // Null-terminate the string

    return strstr(flatArray, str) != NULL;
}

int main() {
    srand(time(0));  // Seed for random number generation
    char arr[ROWS][COLS];
    int studentID[4] = {1, 2, 3, 4}; // Replace with your student ID last 4 digits
    char input[100];
    int score = 0;

    generateArray(arr, studentID);

    while (1) {
        printf("\nCurrent Array:\n");
        printArray(arr);
        printf("Enter a string to search (or 'END' to stop): ");
        scanf("%s", input);

        if (strcmp(input, "END") == 0) {
            break;
        }

        if (searchString(arr, input)) {
            score++;
            printf("String found! Score: %d\n", score);
        } else {
            score--;
            printf("String not found! Score: %d\n", score);
        }

        // Repopulate the array with new random characters
        generateArray(arr, studentID);
    }

    printf("Final Score: %d\n", score);
    return 0;
}

