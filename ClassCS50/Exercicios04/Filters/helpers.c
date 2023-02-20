#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int media = (int)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = media;
            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int avgR = 0;
    int avgG = 0;
    int avgB = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (round(width / 2)); j++) {
            avgR = image[i][j].rgbtRed;
            avgG = image[i][j].rgbtGreen;
            avgB = image[i][j].rgbtBlue;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - 1 - j].rgbtRed = avgR;
            image[i][width - 1 - j].rgbtGreen = avgG;
            image[i][width - 1 - j].rgbtBlue = avgB;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE matrizCopia[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrizCopia[i][j] = image[i][j];
        }
    }

    int avgR, avgG, avgB, counter;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            avgR = 0;
            avgG = 0;
            avgB = 0;
            counter = 0;

            for (int row = -1; row < 2; row++) {
                for (int column = -1; column < 2; column++) {
                    if (!(i + row < 0 || j + column < 0 || i + row >= height || j + column >= width)) {
                        avgR += matrizCopia[i + row][j + column].rgbtRed;
                        avgG += matrizCopia[i + row][j + column].rgbtGreen;
                        avgB += matrizCopia[i + row][j + column].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(avgR / (float)counter);
            image[i][j].rgbtGreen = round(avgG / (float)counter);
            image[i][j].rgbtBlue = round(avgB / (float)counter);

        }
    }
    return;
}


int limit(int value) {
    if (value > 255) {
        return 255;
    }
    return value;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int media = (int)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            int sepiaRed = (int)round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = (int)round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = (int)round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            sepiaRed = limit(sepiaRed);
            sepiaGreen = limit(sepiaGreen);
            sepiaBlue = limit(sepiaBlue);

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}
