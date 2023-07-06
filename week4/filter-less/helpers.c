#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            int sum = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed);
            int average = round(sum/3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)  sepiaRed = 255;

            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)  sepiaGreen = 255;

            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)  sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = tmp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tp[height][width];// WE MAKE A TEMPORARY IMAGE TO PUT IN BLURED PIXELS
                                // BECAUSE WE CAN'T BLUR EACH PIXEL DIRECLTY
                                // SINCE PREVIOUSLY BLURED PIXELS WILL GIVE A FALSE
                                // VALUE WHEN TRYING TO BLUR NEXT PIXELS
    /*
    int totRed, totGreen, totBue;
    totRed = totGreen = totBue = 0; // That's false, because those variable sould change
    float counter = 0.00;           // with each for loop iteration
    */                              // because otherwise their values will accumulate
                                    // so you have to declare them inside the for loop

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totRed, totGreen, totBue = 0; // HERE
            totRed = totGreen = totBue = 0;
            float counter = 0.00;

            // WE GET [i][j] NEIGHBOORS

            for (int Y = -1; Y < 2; Y++)
            {
                for (int X = -1; X < 2; X++)
                {
                    int nbY = i + Y;
                    int nbX = j + X;
                    // IF THAT NEIGHBOOR IS INVALID, WE GO TO THE NEXT ITERATION
                    if (nbX < 0 || nbY < 0 || nbX > (width-1) || nbY > (height-1) )
                    {
                        continue;
                    }

                    totRed += image[nbY][nbX].rgbtRed;
                    totGreen += image[nbY][nbX].rgbtGreen;
                    totBue += image[nbY][nbX].rgbtBlue;

                    counter ++;
                }
            }
            tp[i][j].rgbtRed = round(totRed/counter);
            tp[i][j].rgbtGreen = round(totGreen/counter);
            tp[i][j].rgbtBlue = round(totBue/counter);
        }
    }
    // WE COPY TP PIXELS TO IMAGE PIXELS
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tp[i][j];
        }
    }
    return;
}
