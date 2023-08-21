// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Prompt user for word on command line
    if (argc != 2)
    {
        printf("Usage: ./novowels word\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
    }
}

// Create replace function
string replace(string word)
{
    int length = strlen(word);
    // Assign new string variable the word so computer can allocate memory
    string converted = word;
    // Loop through each char in string and use switch statement to change vowels
    for (int i = 0; i < length; i++)
    {
        switch (word[i])
        {
            case 'a':
                converted[i] = '6';
                break;
            case 'e':
                converted[i] = '3';
                break;
            case 'i':
                converted[i] = '1';
                break;
            case 'o':
                converted[i] = '0';
                break;
            default:
                converted[i] = word[i];
                break;
        }

    }
    return converted;
}
