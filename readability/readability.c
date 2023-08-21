#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float average(float x, float y);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    // Determine the amount of letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //printf("Letters: %i, Sentences: %i, Words: %i\n", letters, sentences, words);
    // L is the average number of letters per 100 words in the text
    float L = average(letters, words);
    //printf("L: %f\n", L);
    // S is the average number of sentences per 100 words in the text
    float S = average(sentences, words);
    //printf("S: %f\n", S);

    // Coleman-Liau index
    int index = round((0.0588 * L - 0.296 * S) - 15.8);

    // Print result
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// Count the number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return (letters);
}

// Count the number of words
int count_words(string text)
{
    int words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    return (words);
}

// Count the number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences += 1;
        }
    }
    return (sentences);
}

// Calculate averages
float average(float x, float y)
{
    float average;
    average = (x / y) * 100;
    return (average);
}
