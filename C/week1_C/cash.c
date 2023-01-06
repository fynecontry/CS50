/*
Yields the fewest coins possible using a greedy algorithm in given a customer change owed.
*/
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Obtain cents from user
int get_cents(void)
{
    // Prompt user for change owed
    int changeOwed;
    do
    {
        changeOwed = get_int("Change owed: ");
    }
    while (changeOwed < 0);
    return changeOwed;
}

// Return no. of quarters that can be retrieved from cents
int calculate_quarters(int cents)
{
    return (cents / 25);
}

// Return no. of dimes that can be retrieved from cents
int calculate_dimes(int cents)
{
    return (cents / 10);
}

// Return no. of nickels that can be retrieved from cents
int calculate_nickels(int cents)
{
    return (cents / 5);
}

// Return no. of pennies that can be retrieved from cents
int calculate_pennies(int cents)
{
    return (cents / 1);
}
