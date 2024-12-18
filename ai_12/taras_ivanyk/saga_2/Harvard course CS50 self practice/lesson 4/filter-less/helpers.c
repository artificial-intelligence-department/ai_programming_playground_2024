#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            double average = round(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
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
    for(int i = 0 ; i < height; i++){
        for(int j = 0; j < width; j++){
           int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
           int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
           int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

           if(sepiaRed > 255) sepiaRed = 255;
           if(sepiaBlue > 255) sepiaBlue = 255;
           if(sepiaGreen > 255) sepiaGreen = 255;


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
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int red_sum = 0, blue_sum = 0, green_sum = 0;
            int count = 0;

            for(int di = -1; di <= 1; di++){
                for(int dj = -1; dj <= 1; dj++){
                    int ni = i + di;    // row index
                    int nj = j + dj;    // col index

                    if(ni >= 0 && ni < height && nj >= 0 && nj < width){
                        red_sum += image[ni][nj].rgbtRed;
                        blue_sum += image[ni][nj].rgbtBlue;
                        green_sum += image[ni][nj].rgbtGreen;
                        count++;
                    }
                }
            }
            copy[i][j].rgbtRed = red_sum / count;
            copy[i][j].rgbtGreen = green_sum / count;
            copy[i][j].rgbtBlue = blue_sum / count;
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = copy[i][j];
        }
    }
    return;
}
