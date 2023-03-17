#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BLK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file_to_recover\n");
        return 1;
    }

    // Open Memory Card file
    FILE *memoryCard = fopen(argv[1], "r");
    if (memoryCard == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Allocate memory for buffer
    BYTE *buffer = malloc(sizeof(BYTE) * BLK_SIZE);

    // Allocate memory to store image filenames
    char *recoveredFilename = malloc(sizeof(char) * 12);

    int counter = 0;
    FILE *outfile;

    // Read till EOF
    while (fread(buffer, sizeof(BYTE), BLK_SIZE, memoryCard))
    {
        // Check if read chunk begins with a JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Open first JPEG for writing
            if (counter == 0)
            {
                sprintf(recoveredFilename, "img_%03i.jpg", counter);
                outfile = fopen(recoveredFilename, "w");
                if (outfile == NULL)
                {
                    printf("Could not open file for writing.\n");
                    return 1;
                }
                fwrite(buffer, sizeof(BYTE), BLK_SIZE, outfile);
                counter++;
            }
            // Open next image file for writing
            else
            {
                fclose(outfile);
                sprintf(recoveredFilename, "img_%03i.jpg", counter);
                outfile = fopen(recoveredFilename, "w");
                if (outfile == NULL)
                {
                    printf("Could not open file for writing.\n");
                    return 1;
                }
                fwrite(buffer, sizeof(BYTE), BLK_SIZE, outfile);
                counter++;
            }
        }
        // Continue writing 512 bytes chunks if not a JPEG header
        else
        {
            if (counter != 0)
            {
                fwrite(buffer, sizeof(BYTE), BLK_SIZE, outfile);
            }
        }
    }
    fclose(outfile);
    free(buffer);
    free(recoveredFilename);
    fclose(memoryCard);
}