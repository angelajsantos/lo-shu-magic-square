#include <stdio.h>
#include <stdlib.h>
#include <time.h> //library to get random number generator

//checks if grid is a magic square
int checkMagicSquare(int square[3][3]) {
    int sum = 0;
    int targetSum = 15; //add rows and col must add up to 15

    //check rows and columns with inner for loop since grid is two-dimensional
    for(int i = 0; i < 3; i++) { //iterates through row 
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < 3; j++){ //iterates through col
            rowSum = rowSum + square[i][j]; 
            colSum = colSum + square[j][i];
        }
        if (rowSum != targetSum || colSum != targetSum) {
            return 0;
        }
    }

    //check diagonals
    if((square[0][0] + square[1][1] + square[2][2] != targetSum) || square[0][2] + square[1][1] + square[2][0] != targetSum) {
        return 0;
    }
    return 1;
}

//print grid 
void printGrid(int square[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j=0; j <3; j++) {
            printf("%d ", square[i][j]);
        }
        printf("]\n");
    }
}

void main() {

    int grid[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};// two-dimensional array for grid
    int counter = 0; //counter for total num of squares generated
    int contained[10] = {0}; //keeps track of numbers in created squares

    //random number generator
    time_t r;
    srand((unsigned) time(&r));

    //creating squares
    do {
        counter++;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num;
                do {
                    num = rand() % 9 + 1; //gets a random number between 1 and 9
                } while (contained[num]); //check if the number has already been used
                grid[i][j] = num;
                contained[num] = 1;       //marks number as used
            }
        }
        for (int i = 0; i < 10; i++) {
            contained[i] = 0;
        }
    } while(!checkMagicSquare(grid));

    printf("Total number of squares generated and tested before success: %d\n", counter);
    printGrid(grid);
}



