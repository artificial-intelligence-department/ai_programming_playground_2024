from cs50 import get_string

def main():
    text = get_string("Text: ")
    L = count_letters(text) / count_words(text) * 100
    S = count_sentences(text) / count_words(text) * 100
    
    index = 0.0588 * L - 0.296 * S - 15.8
    index = round(index)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    letters_count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters_count += 1
    return letters_count

def count_words(text):
    words_count = 0
    for i in range(len(text)):
        if text[i].isspace():
            words_count += 1
    return words_count + 1   # for last word

def count_sentences(text):
    sentences_count = 0
    for i in range(len(text)):
        if text[i] in [".","?","!"]:
            sentences_count += 1
    return sentences_count

main()

