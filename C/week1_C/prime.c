/*
An algorithm to generate all prime numbers in a range specified by the user.
*/

#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // prompt user for min. number
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // prompt user for max. number
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Loop through min and max and display prime numbers
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Checks if value passed is a prime number
bool prime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
