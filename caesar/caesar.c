#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Check for only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check that the command-line argument is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);
    // Prompt user for the plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    // For each letter in the plaintext, shift letter by the key
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        char cipher_letter = rotate(plaintext[i], key);
        printf("%c", cipher_letter);
    }

    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    // Loop through string and check that each character is a digit
    bool check_key = false;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (isdigit((s[i])))
        {
            check_key = true;
        }
        else
        {
            check_key = false;
        }
    }
    return check_key;
}

char rotate(char c, int n)
{
    // Shift the only the alphabet characters by the inputted number amount
    if (islower(c))
    {
        //Checks if c is lowercase letter, then subtracts by 'a' to treat 'a' as 0 to perform arithmetic. This is to done to be able to use modulus to wrap around the alphabet when shifting.
        c = c - 'a';
        c = (c + n) % 26;
        c = c + 'a';
        return c;
    }
    else if (isupper(c))
    {
        //Check if c is uppercase letter, then does the same as the above condition.
        c = c - 'A';
        c = (c + n) % 26;
        c = c + 'A';
        return c;
    }
    else
    {
        //Returns the char unchanged
        return c;
    }
}
