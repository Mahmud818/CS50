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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // struct definition for convolution matrix
    typedef struct
    {
        double blue;
        double green;
        double red;
    }
    conv_matrix;

    // declaration of convolution matrix variables
    conv_matrix Gx;
    conv_matrix Gy;

    ////declaring array of ints to assign rgbt values to
    int a[height][width];
    int b[height][width];
    int c[height][width];
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
    for (int i = 0; i < height; i++)
    {
        for (int f = 0; f < width; f++)
        {
            // assigning Gx and Gy value for pixels at corner
            if (i == 0 && f == 0)
            {
                Gx.blue = 2 * (a[i][f + 1]) + 1 * (a[i + 1][f + 1]);
                Gx.green = 2 * (b[i][f + 1]) + 1 * (b[i + 1][f + 1]);
                Gx.red = 2 * (c[i][f + 1]) + 1 * (c[i + 1][f + 1]);

                Gy.blue = 2 * (a[i + 1][f]) + 1 * (a[i + 1][f + 1]);
                Gy.green = 2 * (b[i + 1][f]) + 1 * (b[i + 1][f + 1]);
                Gy.red = 2 * (c[i + 1][f]) + 1 * (c[i + 1][f + 1]);
            }
            // assigning Gx and Gy value for pixels at corner
            else if (i == 0 && f == (width - 1))
            {
                Gx.blue = -2 * (a[i][f - 1]) + -1 * (a[i + 1][f - 1]);
                Gx.green = -2 * (b[i][f - 1]) + -1 * (b[i + 1][f - 1]);
                Gx.red = -2 * (c[i][f - 1]) + -1 * (c[i + 1][f - 1]);

                Gy.blue = 1 * (a[i + 1][f - 1]) + 2 * (a[i + 1][f]);
                Gy.green = 1 * (b[i + 1][f - 1]) + 2 * (b[i + 1][f]);
                Gy.red = 1 * (c[i + 1][f - 1]) + 2 * (c[i + 1][f]);
            }
            // assigning Gx and Gy value for pixels at corner
            else if (i == (height - 1) && f == 0)
            {
                Gx.blue = 1 * (a[i - 1][f + 1]) + 2 * (a[i][f + 1]);
                Gx.green = 1 * (b[i - 1][f + 1]) + 2 * (b[i][f + 1]);
                Gx.red = 1 * (c[i - 1][f + 1]) + 2 * (c[i][f + 1]);

                Gy.blue = -2 * (a[i - 1][f]) + -1 * (a[i - 1][f + 1]);
                Gy.green = -2 * (b[i - 1][f]) + -1 * (b[i - 1][f + 1]);
                Gy.red = -2 * (c[i - 1][f]) + -1 * (c[i - 1][f + 1]);
            }
            // assigning Gx and Gy value for pixels at corner
            else if (i == (height - 1) && f == (width - 1))
            {
                Gx.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i][f - 1]);
                Gx.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i][f - 1]);
                Gx.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i][f - 1]);

                Gy.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i - 1][f]);
                Gy.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i - 1][f]);
                Gy.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i - 1][f]);
            }
            // assigning Gx and Gy value for pixels at edge
            else if (i == 0)
            {
                Gx.blue = -2 * (a[i][f - 1]) + -1 * (a[i + 1][f - 1]) + 2 * (a[i][f + 1]) + 1 * (a[i + 1][f + 1]);
                Gx.green = -2 * (b[i][f - 1]) + -1 * (b[i + 1][f - 1]) + 2 * (b[i][f + 1]) + 1 * (b[i + 1][f + 1]);
                Gx.red = -2 * (c[i][f - 1]) + -1 * (c[i + 1][f - 1]) + 2 * (c[i][f + 1]) + 1 * (c[i + 1][f + 1]);

                Gy.blue = 1 * (a[i + 1][f - 1]) + 2 * (a[i + 1][f]) + 1 * (a[i + 1][f + 1]);
                Gy.green = 1 * (b[i + 1][f - 1]) + 2 * (b[i + 1][f]) + 1 * (b[i + 1][f + 1]);
                Gy.red = 1 * (c[i + 1][f - 1]) + 2 * (c[i + 1][f]) + 1 * (c[i + 1][f + 1]);
            }
            // assigning Gx and Gy value for pixels at edge
            else if (f == 0)
            {
                Gx.blue = 1 * (a[i - 1][f + 1]) + 2 * (a[i][f + 1]) + 1 * (a[i + 1][f + 1]);
                Gx.green = 1 * (b[i - 1][f + 1]) + 2 * (b[i][f + 1]) + 1 * (b[i + 1][f + 1]);
                Gx.red = 1 * (c[i - 1][f + 1]) + 2 * (c[i][f + 1]) + 1 * (c[i + 1][f + 1]);

                Gy.blue = -2 * (a[i - 1][f]) + -1 * (a[i - 1][f + 1]) + 2 * (a[i + 1][f]) + 1 * (a[i + 1][f + 1]);
                Gy.green = -2 * (b[i - 1][f]) + -1 * (b[i - 1][f + 1]) + 2 * (b[i + 1][f]) + 1 * (b[i + 1][f + 1]);
                Gy.red = -2 * (c[i - 1][f]) + -1 * (c[i - 1][f + 1]) + 2 * (c[i + 1][f]) + 1 * (c[i + 1][f + 1]);
            }
            // assigning Gx and Gy value for pixels at edge
            else if (i == (height - 1))
            {
                Gx.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i][f - 1]) + 1 * (a[i - 1][f + 1]) + 2 * (a[i][f + 1]);
                Gx.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i][f - 1]) + 1 * (b[i - 1][f + 1]) + 2 * (b[i][f + 1]);
                Gx.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i][f - 1]) + 1 * (c[i - 1][f + 1]) + 2 * (c[i][f + 1]);

                Gy.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i - 1][f]) + -1 * (a[i - 1][f + 1]);
                Gy.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i - 1][f]) + -1 * (b[i - 1][f + 1]);
                Gy.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i - 1][f]) + -1 * (c[i - 1][f + 1]);
            }
            // assigning Gx and Gy value for pixels at edge
            else if (f == (width - 1))
            {
                Gx.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i][f - 1]) + -1 * (a[i + 1][f - 1]);
                Gx.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i][f - 1]) + -1 * (b[i + 1][f - 1]);
                Gx.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i][f - 1]) + -1 * (c[i + 1][f - 1]);

                Gy.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i - 1][f]) + 1 * (a[i + 1][f - 1]) + 2 * (a[i + 1][f]);
                Gy.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i - 1][f]) + 1 * (b[i + 1][f - 1]) + 2 * (b[i + 1][f]);
                Gy.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i - 1][f]) + 1 * (c[i + 1][f - 1]) + 2 * (c[i + 1][f]);
            }
            // assigning Gx and Gy value for pixels at middle
            else
            {
                Gx.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i][f - 1]) + -1 * (a[i + 1][f - 1]) + 1 * (a[i - 1][f + 1]) + 2 * (a[i][f + 1]) + 1 *
                          (a[i + 1][f + 1]);
                Gx.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i][f - 1]) + -1 * (b[i + 1][f - 1]) + 1 * (b[i - 1][f + 1]) + 2 * (b[i][f + 1]) + 1 *
                           (b[i + 1][f + 1]);
                Gx.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i][f - 1]) + -1 * (c[i + 1][f - 1]) + 1 * (c[i - 1][f + 1]) + 2 * (c[i][f + 1]) + 1 *
                         (c[i + 1][f + 1]);

                Gy.blue = -1 * (a[i - 1][f - 1]) + -2 * (a[i - 1][f]) + -1 * (a[i - 1][f + 1]) + 1 * (a[i + 1][f - 1]) + 2 * (a[i + 1][f]) + 1 *
                          (a[i + 1][f + 1]);
                Gy.green = -1 * (b[i - 1][f - 1]) + -2 * (b[i - 1][f]) + -1 * (b[i - 1][f + 1]) + 1 * (b[i + 1][f - 1]) + 2 * (b[i + 1][f]) + 1 *
                           (b[i + 1][f + 1]);
                Gy.red = -1 * (c[i - 1][f - 1]) + -2 * (c[i - 1][f]) + -1 * (c[i - 1][f + 1]) + 1 * (c[i + 1][f - 1]) + 2 * (c[i + 1][f]) + 1 *
                         (c[i + 1][f + 1]);
            }
            // calculating for new values of rgbt
            int x = round(sqrt((((Gx.blue) * (Gx.blue)) + ((Gy.blue) * (Gy.blue)))));
            int y = round(sqrt((((Gx.green) * (Gx.green)) + ((Gy.green) * (Gy.green)))));
            int z = round(sqrt((((Gx.red) * (Gx.red)) + ((Gy.red) * (Gy.red)))));
            // check if new values exceed limit and then capping them
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
            //assigning new rgbt values
            image[i][f].rgbtBlue = x;
            image[i][f].rgbtGreen = y;
            image[i][f].rgbtRed = z;
        }

    }
    return;
}
