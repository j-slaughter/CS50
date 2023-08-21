#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int x;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);

    // Prompt for end size
    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);

    // Calculate number of years until we reach threshold
    int years = 0;
    while (x < y)
    {
        x = x + (x / 3) - (x / 4);
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
