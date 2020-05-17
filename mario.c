#include <stdio.h>
#include <cs50.h>
void printMiddleSpaces(void);
void printSideSpaces(int height, int row);
void printPoundSigns(int height, int row);

int main(void)
{
    int height;

    do
    {
        height = get_int("Enter pyrmid height \n");
    }
    while (height > 8 || height < 1);

    for(int row = 1; row <= height; row++)
    {
        //PROCESS COLUMN
        //print [height - row] spaces
        //print [row] #
        //print [2] #
        //print [height - row] spaces   //NOT NEEDED, DON'T NEED TRAILING WHITE SPACES
        //next row
        printSideSpaces(height, row);
        printPoundSigns(height,row);
        printMiddleSpaces();
        printPoundSigns(height,row);
        //printSideSpaces(height, row);
        printf("\n");
    }
}

void printMiddleSpaces(void)
{
    printf("  ");
}

void printSideSpaces(int height, int row)
{
    for(int col = 1; col <= height-row; col++)
    {
        printf(" ");
    }
}

void printPoundSigns(int height, int row)
{
    for(int col = 1; col <= row; col++)
    {
        printf("#");
    }
}


