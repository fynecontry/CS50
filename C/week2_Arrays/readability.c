#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Compute the index using Coleman-Liau's algorithm
    float average_no_letters = (count_letters(text) / (float) count_words(text)) * 100;
    float average_no_sentences = (count_sentences(text) / (float) count_words(text)) * 100;
    float index = 0.0588 * average_no_letters - 0.296 * average_no_sentences - 15.8;

    // Print Grade level according to index
    if ((int)round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else if ((int)round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }

}

int count_letters(string text)
{
    // Counts how many letters in text and returns number
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    // Returns words count
    int count = 0;

    // Create a copy of the passed string in an array of char
    char text_copy[strlen(text)];
    strcpy(text_copy, text);
    // Tokenize each word by a space delimiter
    char *token = strtok(text_copy, " ");
    // Iterate through each token and count words
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }

    // implementation without strtok()
    /*
    int text_length = strlen(text);
    for (int i = 1; i < text_length - 1; i++)
    {
        // Using blanks
        if (isblank(text[i - 1]) == false && isblank(text[i]))
        {
            count++;
        }
    }
    if (isblank(text[text_length - 1]) == false && isalpha(text[text_length - 1]))
    {
        count++;
    }
    */
    return count;
}

int count_sentences(string text)
{
    // Returns number of sentences

    int count = 0;
    // Create a copy of the passed string in an array of char
    char text_copy[strlen(text)];
    strcpy(text_copy, text);
    // Tokenize each word by character delimiters
    char delim[] = ".!?";
    char *token = strtok(text_copy, delim);
    while (token != NULL)
    {
        // Check next character is alphanumeric, space or tab before classifying a sentence
        if (isalnum(*token) || isblank(*token))
        {
            count++;
        }
        token = strtok(NULL, delim);
    }
    return count;
}