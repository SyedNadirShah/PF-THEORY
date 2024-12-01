/*
Name: syed Nadir Shah
ID:24k-0011
Des: simulate a simple grid-based adventure game using a 2D array.
*/
#include <stdio.h>

// Grid size
#define SIZE 5

// Function to display the grid
void displayGrid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to find the player's current position
void findPlayerPosition(char grid[SIZE][SIZE], int *playerRow, int *playerCol) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 'P') {
                *playerRow = i;
                *playerCol = j;
                return;
            }
        }
    }
}

// Function to handle the player's move
void movePlayer(char grid[SIZE][SIZE], char move, int *playerRow, int *playerCol, int *itemsCollected) {
    int newRow = *playerRow;
    int newCol = *playerCol;

    if (move == 'W' || move == 'w') newRow--;  // Move up
    else if (move == 'S' || move == 's') newRow++;  // Move down
    else if (move == 'A' || move == 'a') newCol--;  // Move left
    else if (move == 'D' || move == 'd') newCol++;  // Move right
    else {
        printf("Invalid input. Use W, S, A, D to move or Q to quit.\n");
        return;
    }

    // Check if the move is within bounds and not an obstacle
    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && grid[newRow][newCol] != 'X') {
        if (grid[newRow][newCol] == 'I') {
            (*itemsCollected)++;
            printf("You collected an item! Total items collected: %d\n", *itemsCollected);
        }

        // Update the grid
        grid[*playerRow][*playerCol] = ' ';  // Clear old position
        grid[newRow][newCol] = 'P';  // Update new position

        // Update player position
        *playerRow = newRow;
        *playerCol = newCol;
    } else {
        printf("Invalid move! You hit a wall or obstacle.\n");
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow, playerCol;
    int itemsCollected = 0;
    char move;

    findPlayerPosition(grid, &playerRow, &playerCol);

    while (1) {
        displayGrid(grid);
        printf("Enter your move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        if (move == 'Q' || move == 'q') {
            printf("Thanks for playing! You collected %d items.\n", itemsCollected);
            break;
        }

        movePlayer(grid, move, &playerRow, &playerCol, &itemsCollected);
    }

    return 0;
}

