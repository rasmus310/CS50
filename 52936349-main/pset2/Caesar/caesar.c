#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if exactly one command-line argument is provided
    if (argc != 2)
    {
        printf("Error. Provide only one key\n");
        return 1;
    }

    // Check if the provided argument is composed of digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Error. Please provide an integer\n");
            return 1;
        }
    }

    // Convert the argument to an integer, which will be used as the Caesar cipher key
    int k = atoi(argv[1]);

    // Prompt the user to enter the plaintext
    string plain = get_string("Write your text here: ");

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        char cipher = '\0'; // Initialize the cipher character

        // If the current character is uppercase
        if (isupper(plain[i]))
        {
            // Apply the Caesar cipher encryption for uppercase letters
            cipher = ((plain[i] - 'A' + k) % 26) + 'A';
        }
        // If the current character is lowercase
        else if (islower(plain[i]))
        {
            // Apply the Caesar cipher encryption for lowercase letters
            cipher = ((plain[i] - 'a' + k) % 26) + 'a';
        }

        // Print the resulting character
        printf("%c", cipher);
    }

    // Print a newline character to end the ciphertext
    printf("\n");

    return 0;
}
