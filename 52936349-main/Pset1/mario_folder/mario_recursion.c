#include <cs50.h>
#include <stdio.h>


void draw(int h);

int main(void)
{
    int height = get_int("Enter the height of the pyramid: ");
    draw(height);
}

void draw(int h)
{
    // Base case: Stop when h reaches 0
    if (h == 0)
    {
        return;
    }

    // First, recursively draw h-1 rows
    draw(h - 1);

    // Then, print the current row of hash symbols
    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}


