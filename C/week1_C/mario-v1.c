/*
Displays ascii art of half pyramid of certain height n.
Where n - is supplied by user.

inspired by Mario Brothers.
Towards the end of the world 1-1 Mario must ascend right-aligned pyramid of blocks
*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Prompt user for input
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop to print ascii art
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}