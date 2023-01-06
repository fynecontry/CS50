/*
Calculates the total or average number of hours spent on CS50,
across a given number of weeks. Based on user's input.
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculates the total hours or average hours based on user's output
float calc_hours(int hours[], int weeks, char output)
{
    float total_hours = 0.0;

    // Calulates total hours
    for (int i = 0; i < weeks; i++)
    {
        total_hours += hours[i];
    }

    // Determine return values based on T(total_hours) or A(average_hours)
    if (output == 'T')
    {
        return total_hours;
    }
    // For average hours
    return total_hours / weeks;
}