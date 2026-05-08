#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        // Left pyramid spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Left pyramid hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // The gap
        printf("  ");
        // Right pyramid hashes
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
