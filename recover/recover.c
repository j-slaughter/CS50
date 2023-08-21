#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    // Open memory card file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }
    // Create buffer to read into
    BYTE *buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);
    if (buffer == NULL)
    {
        fclose(file);
        printf("Cannot allocate memory.\n");
        return 2;
    }
    // Keep count of number of jpegs found
    int f_count = 0;
    // Create array for outfile filename (###.jpg)
    char outfile[8];
    /* Create file pointer (img) and assign NULL address for now.
        When compiling with the file pointer created in the if/else
        statement in the while loop, clang declared c:64 fclose(img)
        to be an undeclared identifier */
    FILE *img = NULL;
    // Read jpegs from memory card
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check for jpeg header signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if first jpeg found
            if (f_count == 0)
            {
                // Create new jpeg file
                sprintf(outfile, "%03i.jpg", f_count);
                // Open output file
                img = fopen(outfile, "w");
                if (img == NULL)
                {
                    fclose(file);
                    printf("Cannot open file.\n");
                    return 1;
                }
            }
            else
            {
                // If not first jpeg, close previous jpeg file
                fclose(img);
                // Create new jpeg file
                sprintf(outfile, "%03i.jpg", f_count);
                // Open output file
                img = fopen(outfile, "w");
                if (img == NULL)
                {
                    fclose(file);
                    printf("Cannot open file.\n");
                    return 1;
                }
            }
            // Write to output file
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            f_count++;
        }
        // If jpeg header not found
        else
        {
            // Check if already found jpeg
            if (f_count > 0)
            {
                // Continue writing to output file
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            }
        }
    }
    // Free allocated memory
    free(buffer);
    // Close files
    fclose(file);
    fclose(img);
}
