/*
Binary Image Object Detection
Engr. Rolando Ilagan II
June 15, 2020
*/
#include <stdio.h>

void removeObject(int *binImage, int inRow, int inColumn, int rows, int columns){

    *(binImage + (inRow*columns) + inColumn) = 0;

    //TOP
    if(inRow > 0){
        int topRow = inRow - 1;
        int topColumn = inColumn;
        if(1 == *(binImage + (topRow*columns) + topColumn)){
            removeObject((int *)binImage, topRow, topColumn, rows, columns);
        }
    }

    //BOTTOM
    if(inRow < rows){
        int botRow = inRow + 1;
        int botColumn = inColumn;
        if(1 == *(binImage + (botRow*columns) + botColumn)){
            removeObject((int *)binImage, botRow, botColumn, rows, columns);
        }
    }

    //LEFT
    if(inColumn > 0){
        int leftRow = inRow;
        int leftColumn = inColumn - 1;
        if(1 == *(binImage + (leftRow*columns) + leftColumn)){
            removeObject((int *)binImage, leftRow, leftColumn, rows, columns);
        }
    }

    //RIGHT
    if(inColumn < columns){
        int rightRow = inRow;
        int rightColumn = inColumn + 1;
        if(1 == *(binImage + (rightRow*columns) + rightColumn)){
            removeObject((int *)binImage, rightRow, rightColumn, rows, columns);
        }
    }
}

int main()
{
    int rows, columns;
    int currRow, currColumn;
    int count = 0;

    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &columns);


    int binImage[rows][columns];

    printf("Please enter the binary image by rows and space-separated columns\n");
    for (currRow=0; currRow<rows; currRow++){
        for(currColumn=0; currColumn<columns; currColumn++){
            scanf("%d", &binImage[currRow][currColumn]);
        }
    }

    for (currRow=0; currRow<rows; currRow++){
        for(currColumn=0; currColumn<columns; currColumn++){
            if(binImage[currRow][currColumn] == 1){
                count++;
                removeObject((int *)binImage, currRow, currColumn, rows, columns);
            }
        }
    }

    printf("Number of 4-connected objects: %d\n", count);
    system("pause");
}
