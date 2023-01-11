// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define ARGS_SIZE 2

string replace(string word);

int main(int argc, string argv[])
{
    // accepts one word only
    if (argc != ARGS_SIZE)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    printf("%s\n", replace(argv[1]));
}

// Replaces vowels with numbers in word and returns value
string replace(string word)
{
    // Check every letter for vowels and replace
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;

            default:
                break;
        }
    }
    return word;
}