/*
Name: syed Nadir Shah
ID:24k-0011
Des: generate both a horizontal and vertical histogram based on user input
*/
#include <stdio.h>

void printHorizontalHistogram(int values[], int count) {
	int i, j;
    printf("Horizontal Histogram:\n");
    for (i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printVerticalHistogram(int values[], int count) {
    printf("\nVertical Histogram:\n");

    int i, j, max = 0;
    for (i = 0; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }

    for (i = max; i > 0; i--) {
        for ( j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("*  ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < count; i++) {
        printf("%d  ", values[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {3, 5, 1, 4};
    int count = sizeof(values) / sizeof(values[0]);

    printHorizontalHistogram(values, count);
    printVerticalHistogram(values, count);

    return 0;
}

