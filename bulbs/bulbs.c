#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    // Prompt user for message
    string text = get_string("Message: ");

    // Convert text to ASCII integers
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        text[i] = (int) text[i];
        // Convert integers to binary bytes
        int binary_text[BITS_IN_BYTE];
        int b = 0;
        do
        {
            int bit = (text[i]) % 2;
            if (bit == 0)
            {
                binary_text[((BITS_IN_BYTE) - 1) - b] = 0;
            }
            else if (bit != 0)
            {
                binary_text[((BITS_IN_BYTE) - 1) - b] = 1;
            }
            text[i] = (text[i] / 2);
            b++;
        }
        while (text[i] > 0);

        // Add the remaining bits to make 8 bits total
        while (b < BITS_IN_BYTE)
        {
            binary_text[((BITS_IN_BYTE) - 1) - b] = 0;
            b++;
        }
        // Print out light bulbs for each bit
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(binary_text[j]);
        }
        // Print new line between each character
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
