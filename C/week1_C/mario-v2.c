/*
Displays ascii art of adjacent pyramids of certain height.
Where n - is supplied by user.

inspired by Mario Brothers.
Towards the end of the world 1-1 Mario must hop over adjacent pyramids pyramid of blocks
*/
#include <cs50.h>
#include <stdio.h>

#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

int main(void)
{
    int height;
    // prompt user for height between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    // Loop through height
    for (int i = 0; i < height; i++)
    {
        // print art for rows
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        // print art for reversed shape
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}