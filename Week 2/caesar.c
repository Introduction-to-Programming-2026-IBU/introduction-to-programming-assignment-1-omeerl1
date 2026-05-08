#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if user provided exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verify the key is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
            printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
        else if (islower(plaintext[i]))
            printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}
