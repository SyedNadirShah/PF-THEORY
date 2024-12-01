/*
Name: syed Nadir Shah
ID:24k-0011
Des: finding the second smallest number in the array
*/
#include <stdio.h>

int main() {
	int i;
    int arr[5];
    int smallest = 9999, second_smallest = 9999;

    // Input 5 elements in the array
    printf("Input 5 elements in the array (value must be < 9999):\n");
    for (i = 0; i < 5; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
        
        // Ensure the value is less than 9999
        if (arr[i] >= 9999) {
            printf("Invalid input. Please enter a value less than 9999.\n");
            return 1; // Exit the program if invalid input
        }

        // Find the smallest and second smallest elements
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    // Check if we found a valid second smallest element
    if (second_smallest == 9999) {
        printf("All elements are the same or there's no valid second smallest.\n");
    } else {
        printf("The Second smallest element in the array is: %d\n", second_smallest);
    }

    return 0;
}

