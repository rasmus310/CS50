#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do // Makes a do-loop that becomes true if the height is more than 1 and less than 8
    {
        height = get_int("Height: "); // making a varible called height, and when program starts it starts with asking the height
    }
    while (height < 1 || height > 8); //  

for (int i = 1; i <= height; i++) // makes a for-loop that have three parts. this just explain the colums of the pyramid
{
for (int j = 0; j < height - i; j++) // sets up the dots in the rows
    {
    printf(" ");
    }
    for (int k = 0; k < i; k++) //sets up the hastags in the rows
    printf("#");
    {
    printf("\n");
    }
}
}

