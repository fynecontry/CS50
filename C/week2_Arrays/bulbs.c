#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
const int BASE = 2;

void print_bulb(int bit);

void num_to_binary_converter(int num, int bits_array[]);

int main(void)
{
    // Get string from user
    string message = get_string("Message: ");

    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // Initialize bits to 0
        int bits_array [] = {0, 0, 0, 0, 0, 0, 0, 0};
        num_to_binary_converter((int)message[i], bits_array);
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(bits_array[j]);
        }
        printf("\n");
    }
}

void num_to_binary_converter(int num, int bits_array[])
{
    // Converter number to base 2 and store in bits_array
    int count = 1;
    while (num != 0)
    {
        bits_array[BITS_IN_BYTE - count] = num % BASE;
        count++;
        num /= BASE;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}