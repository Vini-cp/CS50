#include <stdio.h>
#include <math.h>

typedef struct
{
    int  rgbtBlue;
    int  rgbtGreen;
    int  rgbtRed;
}
RGBTRIPLE;

void conditions(int height, int width, int i, int j, int *p);

int main()
{
    int height = 3;
    int width = 3;

    RGBTRIPLE image[height][width];

    image[0][0].rgbtBlue = 10;
    image[0][0].rgbtGreen = 20;
    image[0][0].rgbtRed = 30;

    image[0][1].rgbtBlue = 40;
    image[0][1].rgbtGreen = 50;
    image[0][1].rgbtRed = 60;

    image[0][2].rgbtBlue = 70;
    image[0][2].rgbtGreen = 80;
    image[0][2].rgbtRed = 90;

    image[1][0].rgbtBlue = 110;
    image[1][0].rgbtGreen = 130;
    image[1][0].rgbtRed = 140;

    image[1][1].rgbtBlue = 120;
    image[1][1].rgbtGreen = 140;
    image[1][1].rgbtRed = 150;

    image[1][2].rgbtBlue = 130;
    image[1][2].rgbtGreen = 150;
    image[1][2].rgbtRed = 160;

    image[2][0].rgbtBlue = 200;
    image[2][0].rgbtGreen = 210;
    image[2][0].rgbtRed = 220;

    image[2][1].rgbtBlue = 220;
    image[2][1].rgbtGreen = 230;
    image[2][1].rgbtRed = 240;

    image[2][2].rgbtBlue = 240;
    image[2][2].rgbtGreen = 250;
    image[2][2].rgbtRed = 260;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d, %d, %d\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
        }
        printf("\n");
    }

    float avgRed = 0;
    float avgGreen = 0;
    float avgBlue = 0;

    int limits[5];
    int *p;
    p = limits;

    RGBTRIPLE image_test[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            conditions(height, width, i, j, p);

            for (int k = limits[0]; k <= limits[1]; k++)
            {
                for (int l = limits[2]; l <=  limits[3]; l++)
                {
                    avgRed = avgRed + image[k][l].rgbtRed;
                    avgGreen = avgGreen + image[k][l].rgbtGreen;
                    avgBlue = avgBlue + image[k][l].rgbtBlue;
                }
            }

            limits[4] = (limits[1] - limits[0] + 1) * (limits[3] - limits[2] + 1);

            avgRed = (float) avgRed / limits[4];
            avgGreen = (float) avgGreen / limits[4];
            avgBlue = (float) avgBlue / limits[4];

            image_test[i][j].rgbtRed = (int) round(avgRed);
            image_test[i][j].rgbtGreen = (int) round(avgGreen);
            image_test[i][j].rgbtBlue = (int) round(avgBlue);

            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = image_test[i][j].rgbtRed;
            image[i][j].rgbtGreen = image_test[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image_test[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d, %d, %d\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
        }
        printf("\n");
    }

    return 0;
}

void conditions(int height, int width, int i, int j, int *p)
{

    if (i > 0)
    {
        p[0] = i - 1;
    }
    else
    {
        p[0] = i;
    }

    if (i < height - 1)
    {
        p[1] = i + 1;
    }
    else
    {
        p[1] = i;
    }

    if (j > 0)
    {
        p[2] = j - 1;
    }
    else
    {
        p[2] = j;
    }

    if (j < width - 1)
    {
        p[3] = j + 1;
    }
    else
    {
        p[3] = j;
    }

}