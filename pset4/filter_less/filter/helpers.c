#include "helpers.h"
#include <math.h>
#include <stdio.h>

void conditions(int height, int width, int i, int j, int *p);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float aux = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Average of RGB
            aux = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = (int) round(aux);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // The sepia color values should be calculated based on the original color values per the below
            sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // Check if value exceeds 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = (int) round(sepiaBlue);
            image[i][j].rgbtGreen = (int) round(sepiaGreen);
            image[i][j].rgbtRed = (int) round(sepiaRed);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int refRed;
    int refGreen;
    int refBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Reflecting horizontally the image
            refRed = image[i][width - j - 1].rgbtRed;
            refGreen = image[i][width - j - 1].rgbtGreen;
            refBlue = image[i][width - j - 1].rgbtBlue;

            // Swapping variables
            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtBlue = refBlue;
            image[i][j].rgbtGreen = refGreen;
            image[i][j].rgbtRed = refRed;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float avgRed = 0;
    float avgGreen = 0;
    float avgBlue = 0;

    int limits[5];
    int *p;
    p = limits;

    // image copy
    RGBTRIPLE image_test[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // check the boundaries
            conditions(height, width, i, j, p);

            for (int k = limits[0]; k <= limits[1]; k++)
            {
                for (int l = limits[2]; l <=  limits[3]; l++)
                {
                    // summing all values
                    avgRed = avgRed + image[k][l].rgbtRed;
                    avgGreen = avgGreen + image[k][l].rgbtGreen;
                    avgBlue = avgBlue + image[k][l].rgbtBlue;
                }
            }

            limits[4] = (limits[1] - limits[0] + 1) * (limits[3] - limits[2] + 1);

            // average values
            avgRed = (float) avgRed / limits[4];
            avgGreen = (float) avgGreen / limits[4];
            avgBlue = (float) avgBlue / limits[4];

            // assigning the round variables
            image_test[i][j].rgbtRed = (int) round(avgRed);
            image_test[i][j].rgbtGreen = (int) round(avgGreen);
            image_test[i][j].rgbtBlue = (int) round(avgBlue);

            // restarting variables
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // assigning the values
            image[i][j].rgbtRed = image_test[i][j].rgbtRed;
            image[i][j].rgbtGreen = image_test[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image_test[i][j].rgbtBlue;
        }
    }

    return;
}

// function to decide the for loop
void conditions(int height, int width, int i, int j, int *p)
{

    // i upper boundary
    if (i > 0)
    {
        p[0] = i - 1;
    }
    else
    {
        p[0] = i;
    }

    // i lower boundary
    if (i < height - 1)
    {
        p[1] = i + 1;
    }
    else
    {
        p[1] = i;
    }

    // j upper boundary
    if (j > 0)
    {
        p[2] = j - 1;
    }
    else
    {
        p[2] = j;
    }

    // j lower boundary
    if (j < width - 1)
    {
        p[3] = j + 1;
    }
    else
    {
        p[3] = j;
    }

}