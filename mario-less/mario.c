#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Print out hashes base on height
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Equation to print number of spaces first
            if ((i + j) < (n - 1))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
