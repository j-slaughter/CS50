#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_letters(string s);
bool no_repeats(string word);
char rotate(char c, string key);

int main(int argc, string argv[])
{
    const int ALPHA_LENGTH = 26;
    // Check user inputted correct command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != ALPHA_LENGTH || only_letters(argv[1]) == false)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (no_repeats(argv[1]) == false)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // Prompt user for plain text
        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");
        // For each letter in the plaintext, shift letter by the key
        for (int i = 0, length = strlen(plaintext); i < length; i++)
        {
            char cipher_letter = rotate(plaintext[i], argv[1]);
            printf("%c", cipher_letter);
        }
        printf("\n");
        return 0;
    }
}

bool only_letters(string s)
{
    // Loop through string and check that each character is a letter
    bool check_key = false;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (isalpha((s[i])))
        {
            check_key = true;
        }
        else
        {
            check_key = false;
            return check_key;
        }
    }
    return check_key;
}

bool no_repeats(string word)
{
    // Loop through string and check that for any repeating characters
    bool no_repeats = false;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        char letter = tolower(word[i]);
        for (int j = i + 1; j < length; j++)
        {
            if (letter == tolower(word[j]))
            {
                no_repeats = false;
                return no_repeats;
            }
        }
    }
    // Return true if no repeats found
    no_repeats = true;
    return no_repeats;

}

char rotate(char c, string key)
{
    // Find alphabetical number of c and return key letter at that position
    char cipher;
    if (isupper(c))
    {
        c = c - 'A';
        cipher = key[(int) c];
        cipher = toupper(cipher);
        return cipher;
    }
    else if (islower(c))
    {
        c = c - 'a';
        cipher = key[(int) c];
        cipher = tolower(cipher);
        return cipher;
    }
    else
    {
        return c;
    }
}
