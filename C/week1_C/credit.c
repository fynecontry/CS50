/*
credit.c - determines the validity of a credit card using Luhn's Algorithm.
Displays card vendor if credit card is valid
*/
#include <cs50.h>
#include <stdio.h>

long get_credit_card(void);
bool is_valid(long credit_card);
int get_len(long credit_card);
bool is_valid_checksum(int sum);
string get_card_vendor(long n);

// Digits representing each card vendor
const int amex1 = 34;
const int amex2 = 37;
const int master_card_lower_bound = 51;
const int master_card_upper_bound = 55;
const int visa = 4;

// range of card sizes
const int card_size_lower_bound = 13;
const int card_size_upper_bound = 16;

int main(void)
{
    long credit_card = get_credit_card();
    // Quit if invalid number
    if (is_valid(credit_card) == false)
    {
        return 0;
    }
    // Store credit card vendor
    string card_vendor = get_card_vendor(credit_card);


    int sum = 0, counter = 0, current_digit;
    int temp_card = credit_card;

    // Compute checksum using Luhn's Algorithm
    while (credit_card != 0)
    {
        counter++;
        // Check if counter is even
        if (counter % 2 == 0)
        {
            current_digit = (credit_card % 10) * 2;
            // Split current_digit if more than a digit
            if (get_len(current_digit > 1))
            {
                sum += (current_digit % 10) + (current_digit / 10);
            }
            else
            {
                sum += current_digit;
            }
        }
        else
        {
            sum += credit_card % 10;
        }
        credit_card /= 10;
    }

    if (is_valid_checksum(sum))
    {
        printf("%s\n", card_vendor);
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_credit_card(void)
{
    // prompt user for credit card no.
    return get_long("Number: ");
}

// Check credit_card validity
bool is_valid(long credit_card)
{
    if ((get_len(credit_card) < card_size_lower_bound) || (get_len(credit_card) > card_size_upper_bound))
    {
        printf("INVALID\n");
        return false;
    }
    return true;
}

// Returns how many digits are in a supplied card
int get_len(long credit_card)
{
    int counter = 0;
    while (credit_card != 0)
    {
        counter++;
        credit_card /= 10;
    }
    return counter;
}

// checksum validity
bool is_valid_checksum(int sum)
{
    return (sum % 10 == 0);
}

// Returns the card vendor name based on card first 2 digits
string get_card_vendor(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    if (n == amex1 || n == amex2)
    {
        return "AMEX";
    }
    else if (n >= master_card_lower_bound && n < master_card_upper_bound)
    {
        return "MASTERCARD";
    }
    else if (n / 10 == visa)
    {
        return "VISA";
    }
    return "INVALID";
}