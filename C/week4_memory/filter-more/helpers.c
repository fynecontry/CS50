#include "helpers.h"
#include "math.h"
#include "stdlib.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average of each pixel
            double average_pixel = round((double)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = average_pixel;
            image[i][j].rgbtBlue = average_pixel;
            image[i][j].rgbtGreen = average_pixel;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Dynamically allocate memory to store sepia variable
            int *sepiaRed = malloc(sizeof(int));
            int *sepiaGreen = malloc(sizeof(int));
            int *sepiaBlue = malloc(sizeof(int));

            // Calculate the sepiaRGB using sepia algorithm
            *sepiaRed =  round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            *sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            *sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = (*sepiaRed < 255) ? *sepiaRed : 255;
            image[i][j].rgbtGreen = (*sepiaGreen < 255) ? *sepiaGreen : 255;
            image[i][j].rgbtBlue = (*sepiaBlue < 255) ? *sepiaBlue : 255;

            // free unused memory
            free(sepiaRed);
            free(sepiaGreen);
            free(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory to temporarily store pixels
    RGBTRIPLE *tmp = malloc(sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, mid = width / 2; j < mid; j++)
        {
            *tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = *tmp;
        }
    }
    free(tmp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for temp image
    RGBTRIPLE(*tempImage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j] = image[i][j];
        }
    }

    // Calculate average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialise RGB variable to store total RGB values
            int totalRed, totalGreen, totalBlue, counter;
            totalRed = totalGreen = totalBlue = counter = 0;

            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows and ignore
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns and ignore
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Add each RGB total if valid
                    totalRed += tempImage[i + k][j + l].rgbtRed;
                    totalGreen += tempImage[i + k][j + l].rgbtGreen;
                    totalBlue += tempImage[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }
            // Insert average values to produce blur
            image[i][j].rgbtRed = round((float)totalRed / counter);
            image[i][j].rgbtGreen = round((float)totalGreen / counter);
            image[i][j].rgbtBlue = round((float)totalBlue / counter);
        }
    }
    free(tempImage);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Initialise convolution matrices Gx & Gy
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Allocate memory for temp image
    RGBTRIPLE(*tempImage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j] = image[i][j];
        }
    }

    float redGx, greenGx, blueGx, redGy, greenGy, blueGy;


    // Calculate average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            redGx = greenGx = blueGx = redGy = greenGy = blueGy = 0;
            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows and ignore
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns and ignore
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Calculate GX and GY values for each pixels
                    redGx += tempImage[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    greenGx += tempImage[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    blueGx += tempImage[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];

                    redGy += tempImage[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    greenGy += tempImage[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    blueGx += tempImage[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
            // Insert average values to produce blur
            int finalRed = round(sqrt(redGx * redGx + redGy * redGy));
            int finalGreen = round(sqrt(greenGx * greenGx + greenGy * greenGy));
            int finalBlue = round(sqrt(blueGx * blueGx + blueGy * blueGy));
            image[i][j].rgbtRed = (finalRed < 255) ? finalRed : 255;
            image[i][j].rgbtGreen = (finalGreen < 255) ? finalGreen : 255;
            image[i][j].rgbtBlue = (finalBlue < 255) ? finalBlue : 255;
        }
    }
    free(tempImage);
    return;
}