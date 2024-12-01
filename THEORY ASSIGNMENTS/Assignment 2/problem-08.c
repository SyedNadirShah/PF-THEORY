/*
Name: syed Nadir Shah
ID:24k-0011
Des:  program that contains the functions for different numerical conversions
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert binary to decimal
int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, remainder;
    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        base *= 2;
        number /= 10;
    }
    return decimal;
}

// Function to convert decimal to binary
int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        binary += (number % 2) * base;
        base *= 10;
        number /= 2;
    }
    return binary;
}

// Function to convert decimal to hexadecimal
void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;
    while (number > 0) {
        int remainder = number % 16;
        if (remainder < 10)
            hex[i] = 48 + remainder;  // 48 = '0'
        else
            hex[i] = 55 + remainder;  // 55 = 'A' - 10
        i++;
        number /= 16;
    }
    hex[i] = '\0';

    printf("Hexadecimal: ");
    for (i--; i >= 0; i--)
        printf("%c", hex[i]);
    printf("\n");
}

// Function to convert hexadecimal to decimal
void HexadecimalToDecimal(char hexNumber[]) {
    int length, base, decimal, i;
    length = strlen(hexNumber);
    base = 1;
    decimal = 0;

    for (i = length - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - 48) * base;  // '0' = 48
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 55) * base;  // 'A' = 65
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            decimal += (hexNumber[i] - 87) * base;  // 'a' = 97
        } else {
            printf("Invalid Hexadecimal Input\n");
            return;
        }
        base *= 16;
    }
    printf("Decimal: %d\n", decimal);
}

// Function to convert binary to hexadecimal
void BinaryToHexadecimal(int number) {
    int decimal;
    decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

// Function to convert hexadecimal to binary
void HexadecimalToBinary(char hexNumber[]) {
    int decimal, base, i, length;
    decimal = 0;
    base = 1;
    length = strlen(hexNumber);

    for (i = length - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - 48) * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 55) * base;
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            decimal += (hexNumber[i] - 87) * base;
        } else {
            printf("Invalid Hexadecimal Input\n");
            return;
        }
        base *= 16;
    }

    printf("Binary: %d\n", DecimalToBinary(decimal));
}

// Menu function
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

