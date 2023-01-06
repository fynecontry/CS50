/*
Determines how long it takes for a population to reach a particular size,
supplied by the user.
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize, endSize, years = 0;
    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int newLlamas, deadLlamas;
    while (startSize < endSize)
    {
        years++;
        newLlamas = startSize / 3;
        deadLlamas = startSize / 4;
        startSize = startSize + newLlamas - deadLlamas;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
