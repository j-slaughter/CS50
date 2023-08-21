from cs50 import get_string


def main():
    # Get text from user
    text = get_string("Text: ")

    # Determine the amount of letters, words, and sentences
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # L is the average number of letters per 100 words in the text
    L = average(letters, words)
    # S is the average number of sentences per 100 words in the text
    S = average(sentences, words)

    # Coleman-Liau Index
    index = round(((0.0588 * L) - (0.296 * S) - 15.8))

    # Print result
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade {}".format(index))


def count_letters(text):
    """ Returns the number of letters in a text"""
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def count_words(text):
    """ Returns the number of words in a text"""
    words = 1
    for char in text:
        if char == ' ':
            words += 1
    return words


def count_sentences(text):
    """ Returns the number of sentences in a text"""
    sentences = 0
    for char in text:
        if (char == '.') or (char == '!') or (char == '?'):
            sentences += 1
    return sentences


def average(x, y):
    """ Returns the average of two numbers"""
    average = (x / y) * 100
    return average


if __name__ == "__main__":
    main()
