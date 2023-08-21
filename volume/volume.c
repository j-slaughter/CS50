// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t *header = malloc(sizeof(uint8_t) * HEADER_SIZE);
    if (header == NULL)
    {
        printf("Cannot allocate memory.\n");
        return 1;
    }
    // Read header from input file
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    // Write header to output file
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t *sample = malloc(sizeof(int16_t));
    if (sample == NULL)
    {
        printf("Cannot allocate memory.\n");
        return 1;
    }
    // Loop through end of input file
    while (fread(sample, sizeof(int16_t), 1, input))
    {
        // Amplify or decrease volume
        *sample *= factor;
        // Write sample to output file
        fwrite(sample, sizeof(int16_t), 1, output);
    }
    // Free memory
    free(header);
    free(sample);

    // Close files
    fclose(input);
    fclose(output);
}
