#include "helpers.h"
#include <stdio.h>
#include <math.h>
void processMiddleRows(int height, int width, RGBTRIPLE image[height][width], int h, int w);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            double average = 0;
            average = round((double)(image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3);

            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int blue = image[h][w].rgbtBlue;
            int green = image[h][w].rgbtGreen;
            int red = image[h][w].rgbtRed;

            int sepiaBlue = round(.272f * red + .534f * green + .131f * blue);
            int sepiaGreen = round(.349f * red + .686f * green + .168f * blue);
            int sepiaRed = round(.393f * red + .769f * green + .189f * blue);

            if (sepiaBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = sepiaBlue;
            }

            if (sepiaGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = sepiaGreen;
            }

            if (sepiaRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = sepiaRed;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int h = 0; h < height; h++)
    {
        // make array to store left pixel
        RGBTRIPLE temp[1];

        for (int w = 0; w < width / 2; w++)
        {
            // store left pixel
            temp[0] = image[h][w];

            // write left pixel
            image[h][w] = image[h][width - w - 1];

            // write right pixel
            image[h][width - w - 1] = temp[0];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for (int h = 0; h < height; h++)
    {

        for (int w = 0; w < width; w++)
        {
            if (0 < h && h < height - 1 && 0 < w && w < width - 1)
            {
                processMiddleRows(height, width, image, h, w);
            }
        }
    }
    return;
}

void processMiddleRows(int height, int width, RGBTRIPLE image[height][width], int h, int w)
{
    //printf("current pixel is %i %i \n", h, w);

    int blueTotal = 0;
    int greenTotal = 0;
    int redTotal = 0;

    for (int a = h - 1; a <= h + 1; a++)
    {
        for (int b = w - 1; b <= w + 1; b++)
        {
            blueTotal += image[a][b].rgbtBlue;
            greenTotal += image[a][b].rgbtGreen;
            redTotal += image[a][b].rgbtRed;
        }
    }

    int blueAverage = round((double)blueTotal / 9);
    int greenAverage = round((double)greenTotal / 9);
    int redAverage = round((double)redTotal / 9);

    image[h][w].rgbtBlue = blueAverage;
    image[h][w].rgbtGreen = greenAverage;
    image[h][w].rgbtRed = redAverage;
}

