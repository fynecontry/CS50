// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Return true is password matches criteria
bool valid(string password)
{
    bool upper_case, lower_case, one_number, one_symbol = false;

    // iterate through each character in password
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (islower(password[i]))
        {
            lower_case = true;
        }
        else if (isupper(password[i]))
        {
            upper_case = true;
        }
        else if (isdigit(password[i]))
        {
            one_number = true;
        }
        else if (!(isalnum(password[i]) || isblank(password[i])))
        {
            one_symbol = true;
        }
    }

    return (lower_case && upper_case && one_number && one_symbol);
}