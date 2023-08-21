#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Sum together the RGB values
            int sum = (image[i][j].rgbtBlue) + (image[i][j].rgbtGreen) + (image[i][j].rgbtRed);
            // Get average and round to closest integer
            int average = round(sum / 3.0);
            // Change RGB values
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
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the sepia value
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // Cap at the maximum value for an 8-bit color (255)
            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Swap pixel values starting with first and last pixels
        int j = 0;
        int k = width - 1;
        while (j < k)
        {
            // Store RGB values of first pixel in temporary variable
            RGBTRIPLE temp = image[i][j];
            // Set RGB values of first pixel to RGB values of last pixel
            image[i][j] = image[i][k];
            // Set RGB values of last pixel to RGB values of first pixel
            image[i][k] = temp;
            // Update index of j and k
            j++;
            k--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make copy of image in order to calculate blur
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Calculate box blur for each pixel
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            int row_num = k + 1;
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            float count = 0.0;
            // Loop through 3x3 block
            while ((row_num > k - 2) && (row_num >= 0))
            {
                // Check for existing next row
                if (row_num == height)
                {
                    row_num--;
                }
                else
                {
                    // Start counting at pixel to right of current pixel
                    int width_num = l + 1;
                    // Check for existing next pixel in row
                    while ((width_num > l - 2) && (width_num >= 0))
                    {
                        if (width_num == width)
                        {
                            width_num--;
                        }
                        else
                        {
                            // Calculate sum of RGB values
                            sum_red += copy[row_num][width_num].rgbtRed;
                            sum_green += copy[row_num][width_num].rgbtGreen;
                            sum_blue += copy[row_num][width_num].rgbtBlue;
                            count++;
                            width_num--;
                        }
                    }
                    row_num--;
                }
            }

            // Find average of RBG values and assign to image pixel
            image[k][l].rgbtRed = round(sum_red / count);
            image[k][l].rgbtGreen = round(sum_green / count);
            image[k][l].rgbtBlue = round(sum_blue / count);
        }
    }
    return;
}
