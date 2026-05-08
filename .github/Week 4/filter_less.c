void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int rounded = round(average);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = rounded;
        }
    }
}
