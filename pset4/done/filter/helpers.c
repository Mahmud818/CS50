#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // assigning rgbt values to float
            float a = image[i][j].rgbtBlue;
            float b = image[i][j].rgbtGreen;
            float c = image[i][j].rgbtRed;
            // calculating and rounding-off of average
            int average = round((a + b + c) / 3);
            //assigning new rgbt values to average for grayscale filter
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a = image[i][j].rgbtBlue;
            int b = image[i][j].rgbtGreen;
            int c = image[i][j].rgbtRed;
            // applying the sepia filter formula
            float sepiaRed = .393 * c + .769 * b + .189 * a;
            float sepiaGreen = .349 * c + .686 * b + .168 * a;
            float sepiaBlue = .272 * c + .534 * b + .131 * a;
            //rounding-off sepia values to nearest whole number
            int x = round(sepiaBlue);
            int y = round(sepiaGreen);
            int z = round(sepiaRed);
            //applying conditions
            if (x > 255)
            {
                x = 255;
            }
            if (y > 255)
            {
                y = 255;
            }
            if (z > 255)
            {
                z = 255;
            }
            //assigning new rgbt values for sepia filter
            image[i][j].rgbtBlue = x;
            image[i][j].rgbtGreen = y;
            image[i][j].rgbtRed = z;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //declaration of integer array of size "width"
    int a[width];
    int b[width];
    int c[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // assigning rgbt values to declared array
            a[j] = image[i][j].rgbtBlue;
            b[j] = image[i][j].rgbtGreen;
            c[j] = image[i][j].rgbtRed;
        }
        for (int f = 0; f < width; f++)
        {
            //assigning new rgbt values for reflect filter
            image[i][f].rgbtBlue = a[width - (1 + f)];
            image[i][f].rgbtGreen = b[width - (1 + f)];
            image[i][f].rgbtRed = c[width - (1 + f)];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // declaring array of floats to assign rgbt values to
    float a[height][width];
    float b[height][width];
    float c[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // assigning rgbt values to decalred array
            a[i][j] = image[i][j].rgbtBlue;
            b[i][j] = image[i][j].rgbtGreen;
            c[i][j] = image[i][j].rgbtRed;
        }
    }
    // assigning new rgbt values to implement blur filter
    for (int i = 0; i < height; i++)
    {
        for (int f = 0; f < width; f++)
        {
            // assigning rgbt value for corner pixel
            if (i == 0 && f == 0)
            {
                image[i][f].rgbtBlue = round((a[i][f] + a[i][f + 1] + a[i + 1][f] + a[i + 1][f + 1]) / 4);
                image[i][f].rgbtGreen = round((b[i][f] + b[i][f + 1] + b[i + 1][f] + b[i + 1][f + 1]) / 4);
                image[i][f].rgbtRed = round((c[i][f] + c[i][f + 1] + c[i + 1][f] + c[i + 1][f + 1]) / 4);
            }
            // assigning rgbt value for corner pixel
            else if (i == 0 && f == (width - 1))
            {
                image[i][f].rgbtBlue = round((a[i][f - 1] + a[i][f] + a[i + 1][f - 1] + a[i + 1][f]) / 4);
                image[i][f].rgbtGreen = round((b[i][f - 1] + b[i][f] + b[i + 1][f - 1] + b[i + 1][f]) / 4);
                image[i][f].rgbtRed = round((c[i][f - 1] + c[i][f] + c[i + 1][f - 1] + c[i + 1][f]) / 4);
            }
            // assigning rgbt value for corner pixel
            else if (i == (height - 1) && f == 0)
            {
                image[i][f].rgbtBlue = round((a[i - 1][f] + a[i - 1][f + 1] + a[i][f] + a[i][f + 1]) / 4);
                image[i][f].rgbtGreen = round((b[i - 1][f] + b[i - 1][f + 1] + b[i][f] + b[i][f + 1]) / 4);
                image[i][f].rgbtRed = round((c[i - 1][f] + c[i - 1][f + 1] + c[i][f] + c[i][f + 1]) / 4);
            }
            // assigning rgbt value for corner pixel
            else if (i == (height - 1) && f == (width - 1))
            {
                image[i][f].rgbtBlue = round((a[i - 1][f - 1] + a[i - 1][f] + a[i][f - 1] + a[i][f]) / 4);
                image[i][f].rgbtGreen = round((b[i - 1][f - 1] + b[i - 1][f] + b[i][f - 1] + b[i][f]) / 4);
                image[i][f].rgbtRed = round((c[i - 1][f - 1] + c[i - 1][f] + c[i][f - 1] + c[i][f]) / 4);
            }
            // assigning rgbt value for edge pixel
            else if (i == 0)
            {
                image[i][f].rgbtBlue = round((a[i][f - 1] + a[i][f] + a[i][f + 1] + a[i + 1][f - 1] + a[i + 1][f] + a[i + 1][f + 1]) / 6);
                image[i][f].rgbtGreen = round((b[i][f - 1] + b[i][f] + b[i][f + 1] + b[i + 1][f - 1] + b[i + 1][f] + b[i + 1][f + 1]) / 6);
                image[i][f].rgbtRed = round((c[i][f - 1] + c[i][f] + c[i][f + 1] + c[i + 1][f - 1] + c[i + 1][f] + c[i + 1][f + 1]) / 6);

            }
            // assigning rgbt value for edge pixel
            else if (f == 0)
            {
                image[i][f].rgbtBlue = round((a[i - 1][f] + a[i - 1][f + 1] + a[i][f] + a[i][f + 1] + a[i + 1][f] + a[i + 1][f + 1]) / 6);
                image[i][f].rgbtGreen = round((b[i - 1][f] + b[i - 1][f + 1] + b[i][f] + b[i][f + 1] + b[i + 1][f] + b[i + 1][f + 1]) / 6);
                image[i][f].rgbtRed = round((c[i - 1][f] + c[i - 1][f + 1] + c[i][f] + c[i][f + 1] + c[i + 1][f] + c[i + 1][f + 1]) / 6);
            }
            // assigning rgbt value for edge pixel
            else if (i == (height - 1))
            {
                image[i][f].rgbtBlue = round((a[i - 1][f - 1] + a[i - 1][f] + a[i - 1][f + 1] + a[i][f - 1] + a[i][f] + a[i][f + 1]) / 6);
                image[i][f].rgbtGreen = round((b[i - 1][f - 1] + b[i - 1][f] + b[i - 1][f + 1] + b[i][f - 1] + b[i][f] + b[i][f + 1]) / 6);
                image[i][f].rgbtRed = round((c[i - 1][f - 1] + c [i - 1][f] + c[i - 1][f + 1] + c[i][f - 1] + c[i][f] + c[i][f + 1]) / 6);
            }
            // assigning rgbt value for edge pixel
            else if (f == (width - 1))
            {
                image[i][f].rgbtBlue = round((a[i - 1][f - 1] + a[i - 1][f] + a[i][f - 1] + a[i][f] + a[i + 1][f - 1] + a[i + 1][f]) / 6);
                image[i][f].rgbtGreen = round((b[i - 1][f - 1] + b[i - 1][f] + b[i][f - 1] + b[i][f] + b[i + 1][f - 1] + b[i + 1][f]) / 6);
                image[i][f].rgbtRed = round((c[i - 1][f - 1] + c[i - 1][f] + c[i][f - 1] + c[i][f] + c[i + 1][f - 1] + c[i + 1][f]) / 6);
            }
            // assigning rgbt value for middle pixel
            else
            {
                image[i][f].rgbtBlue = round((a[i - 1][f - 1] + a[i - 1][f] + a[i - 1][f + 1] + a[i][f - 1] + a[i][f] + a[i][f + 1] + a[i + 1][f -
                                              1] + a[i + 1][f] + a[i + 1][f + 1]) / 9);
                image[i][f].rgbtGreen = round((b[i - 1][f - 1] + b[i - 1][f] + b[i - 1][f + 1] + b[i][f - 1] + b[i][f] + b[i][f + 1] + b[i + 1][f -
                                               1] + b[i + 1][f] + b[i + 1][f + 1]) / 9);
                image[i][f].rgbtRed = round((c[i - 1][f - 1] + c[i - 1][f] + c[i - 1][f + 1] + c[i][f - 1] + c[i][f] + c[i][f + 1] + c[i + 1][f -
                                             1] + c[i + 1][f] + c[i + 1][f + 1]) / 9);
            }

        }
    }
    return;
}
