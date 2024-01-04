#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // initialize the new colors to current image
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
     for(int i = 0; i < height; i++)
    {
        // Iterate only through the first half of the row (up to the midpoint)
        for(int j = 0; j < width / 2; j++)
        {
            //swap the RBGvalues between the left and the right side of a row
            RGBTRIPLE tempRGB = image[i][j];            // Store the pixel from the left side in a temporary variable
            image[i][j] = image[i][width - 1 - j];      // Replace the pixel on the left side with the pixel on the right side
            image[i][width - 1 - j] = tempRGB;          // Replace the pixel on the right side with the stored pixel (temporarily on the left side)
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store the blurred result
    RGBTRIPLE tempimage[height][width];

     for(int i = 0; i < height; i++) // iterate through each pixel in the image (height)
    {
        for(int j = 0; j < width; j++) // iterate through each pixel in the image (width)
        {
            float sumred = 0.0; // initialize the sum of the red color to 0
            float sumgreen = 0.0; // initialize the sum of the green color to 0
            float sumblue = 0.0; // initialize the sum of the blue color to 0
            int counter = 0; // initialize the counter to 0
            for(int x = -1; x <= 1; x++) // iterate through the 3x3 grid around the pixel. (starts at -1 to include the pixel above the current pixel 0 = current pixel and 1 = pixel below the current pixel)
            {
             for (int y = -1; y <= 1; y++) // iterate through the 3x3 grid around the pixel. (starts at -1 to include the pixel to the left of the current pixel 0 = current pixel and 1 = pixel to the right of the current pixel)
             {
                if ((i + x) < 0 || (i + x) >= height || (j + y) < 0 || (j + y) >= width) // check if the pixel is on the edge of the image
                {
                    continue; // skip the pixel if it is on the edge of the image
                }
                else
                {
                    sumred += image[i + x][j + y].rgbtRed; // add the color of the pixel to the sum
                    sumgreen += image[i + x][j + y].rgbtGreen; // add the color of the pixel to the sum
                    sumblue += image[i + x][j + y].rgbtBlue; // add the color of the pixel to the sum
                    counter++; // increment the counter
                }

             }

            }
            // calculating the avererage color of the pixel
                tempimage[i][j].rgbtRed = round(sumred / counter); // round the average to the nearest integer
                tempimage[i][j].rgbtGreen = round(sumgreen / counter); // round the average to the nearest integer
                tempimage[i][j].rgbtBlue = round(sumblue / counter); // round the average to the nearest integer

        }
    }
 for(int i = 0; i < height; i++) // iterate through each pixel
         {
        for(int j = 0; j < width; j++)
            {
            image[i][j].rgbtRed = tempimage[i][j].rgbtRed; // copy the blurred image to the original image
            image[i][j].rgbtGreen = tempimage[i][j].rgbtGreen; // copy the blurred image to the original image
            image[i][j].rgbtBlue = tempimage[i][j].rgbtBlue;    // copy the blurred image to the original image
            }
          }

    return;
}
