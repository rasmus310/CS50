#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int sentences = 0;
    int words = 1;

    string name = get_string("Write your text here: ");

    for(int i = 0; i < strlen(name); i++)
    {
        if (isalpha(name[i])) // if the character in the array in a letter - +1 letter counter
        {
            letters += 1;
        }
        if (name[i] == '.' || name[i] == '?' || name[i] == '!')
        {
            sentences += 1;
        }
        if (name[i] == (' ')) // everytime there is a space between words, counter +1 for words
        {
            words += 1;
        }
    }
    // printf("%i\n", letters);
    // printf("%i\n", sentences);
    // printf("%i\n", words);

    //  Coleman-Liau index

    float L = ((float)letters / (float)words * 100);
    float S = ((float)sentences / (float)words * 100);

    float index = (0.0588 * L - 0.296 * S - 15.8);
    printf("Grade %.f\n", round(index));


    if (index < 1)
    {
        printf("Before grade 1\n");
    }
}
