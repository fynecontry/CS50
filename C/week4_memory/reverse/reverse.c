#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE* inputAudio = fopen(argv[1], "r");
    if (inputAudio == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // Read header
    WAVHEADER *header = malloc(sizeof(BYTE) * HEADER_SIZE);
    fread(header, HEADER_SIZE, 1, inputAudio);

    // Use check_format to ensure WAV format
    if(!check_format(*header))
    {
        printf("%s is not a valid .wav file.\n", argv[1]);
        return 1;
    }

    // Open output file for writing
    FILE* outputAudio = fopen(argv[2], "w");
    if (inputAudio == NULL)
    {
        printf("Could not open %s for writing.\n", argv[2]);
        return 1;
    }

    // Write header to output file
    fwrite(header, HEADER_SIZE, 1, outputAudio);

    // Use get_block_size to calculate size of block
    WORD block_size = get_block_size(*header);

    int buffer[block_size];
    // Get header's position
    long headerEnd = ftell(inputAudio);
    // Seek to end of file
    fseek(inputAudio, block_size, SEEK_END);

    // Write reversed audio to file
    while(ftell(inputAudio) - block_size > headerEnd)
    {
        // Maintain order of channels for stereophonic sound
        fseek(inputAudio, block_size * -2, SEEK_CUR);
        fread(&buffer, block_size, 1, inputAudio);
        fwrite(&buffer, block_size, 1, outputAudio);
    }

    // Close files
    fclose(inputAudio);
    fclose(outputAudio);
    free(header);
}

int check_format(WAVHEADER header)
{
    // Check if header.format contains letter "WAVE"
    if (header.format[0] == 87 && header.format[1] == 65 && header.format[2] == 86 && header.format[3] == 69)
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}