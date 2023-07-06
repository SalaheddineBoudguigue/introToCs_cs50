# TODO

from cs50 import get_string

def main():
    text = get_string("Text: ")

    a = count_letters(text)
    b = count_words(text)
    c = count_sentences(text)

    # Average number of letters per 100 words
    L = (a / b) * 100

    # Average number of sentences per 100 words
    S = (c / b) * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    index = round(index)

    if index < 1 :
        print("Before Grade 1")
    elif index >= 16 :
        print("Grade 16+")
    else :
        print(f"Grade {index}")


def count_letters(text) :
    letters = 0
    for c in text:
        if c.isalpha():
            letters += 1

    return letters


def count_words(text):
    words = 1
    for c in text:
        if c.isspace():
            words += 1

    return words

def count_sentences(text):
    sentences = 0
    for c in text:
        if c in {'.', '!', '?'}:
            sentences += 1

    return sentences

main()