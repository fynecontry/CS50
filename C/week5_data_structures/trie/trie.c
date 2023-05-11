// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names
#include <assert.h>

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
// Protect from overflow -- make much larger.
#define MAXCHAR 2048

typedef struct node_s
{
    bool is_word; // terminal node
    struct node_s *children[SIZE_OF_ALPHABET];
} Node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(Node *current);

// Root of trie
Node *root;

// Buffer to read dog names into
char name[MAXCHAR];

Node *mknode()
{
    Node *n = malloc(sizeof(Node));
    assert(n);
    n->is_word = false;
    for (int i = 0; i < sizeof(n->children) / sizeof(*n->children); i++)
        n->children[i] = 0;
    return n;
}
int main(int argc, char *argv[])
{
    //  Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = mknode();

    // Add words to the trie -- careful, fscanf replaced with fgets is fragile ... https://stackoverflow.com/questions/861793/trouble-reading-a-line-using-fscanf
    while (fgets(name, MAXCHAR, infile))
    {
        // Remove newline character as a result of using fgets
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
        }
        Node *cursor = root;
        //
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == 0)
            {
                // Make Node
                cursor->children[index] = mknode();
            }

            // Go to Node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }
    // change to take root as parameter of check -- no more globals
    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
    return 0;
}


// Complete the check function, return true if found, false if not found
bool check(char *word)
{
    // Set cursor to the root of the trie
    Node *cursor = root;

    // Iterate over word to see if it occurs in trie by traversing every child Node in trie
    // char * c = word;
    for (char *c = word; *c && cursor; c++)
    {
        int index = tolower(*c) - 'a';
        // Return false is letter from word doesn't exists.
        if (!cursor->children[index])
        {
            return false;
        }
        cursor = cursor->children[index];
    }

    return cursor && cursor->is_word;
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(Node *current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i])
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the Node
    // and return to the previous iteration of this function.
    free(current);
}