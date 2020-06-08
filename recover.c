#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void processOutput(unsigned char buffer[512], int *isFirstJpg);
char* generateFileName();

int fileCount = 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    typedef uint8_t BYTE;
    FILE* file = fopen(argv[1], "r");

    int currentBlock = 0;
    int isFirstJpg = 1;
    BYTE buffer[512];

    while (fread(buffer, 1, 512, file) == 512)
    {
         currentBlock++;
         processOutput(buffer, &isFirstJpg);
    }
}

void processOutput(unsigned char buffer[512], int *isFirstJpg)
{
    FILE* outputFile = NULL;

    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        if (*isFirstJpg == 1)
        {
            // first file
            *isFirstJpg = 0;

            outputFile = fopen(generateFileName(), "w");
            fwrite(buffer, 1, 512, outputFile);
            fclose(outputFile);
        }
        else
        {
            //start of next file
            fileCount++;
            outputFile = fopen(generateFileName(), "w");
            fwrite(buffer, 1, 512, outputFile);
            fclose(outputFile);
        }
    }
    else
    {
        // Keep writing to rest of file
        if (*isFirstJpg == 0)
        {
            outputFile = fopen(generateFileName(), "a");
            fwrite(buffer, 1, 512, outputFile);
            fclose(outputFile);
        }
    }
}

char* generateFileName()
{
    char *fileName = malloc(8);

    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;

    char char1 = '.';
    char char2 = 'j';
    char char3 = 'p';
    char char4 = 'g';

    if (fileCount < 10)
    {
        digit3 = fileCount;
    }
    if (fileCount < 100)
    {
        int count = fileCount;
        int currentDigit = 1;

        while (count)
        {
            if (currentDigit == 1)
            {
                digit3 = count % 10;
                count /= 10;
                currentDigit++;
            }
            else
            {
                digit2 = count % 10;
                count /= 10;
            }
        }
    }

    sprintf(fileName, "%i%i%i%c%c%c%c", digit1, digit2, digit3, char1, char2, char3, char4);
    //printf("%s\n", fileName);

    return fileName;
}