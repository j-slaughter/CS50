#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // Determine length of string
    int length = strlen(input);
    // Set base case
    if (length == 1)
    {
        char c = input[0];
        c = (int) c - '0';
        return c;
    }
    // Get the last char of the string
    char c = input[length - 1];
    // Convert the char to its numeric value
    c = (int) c - '0';
    // Remove the last char from the string
    input[length - 1] = '\0';
    // Recursively call the function to return full string converted to integer
    return (convert(input) * 10) + c;
}
