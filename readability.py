import re
from cs50 import get_string


def main():
    inputString = get_string("Text: ")
    processString(inputString)

def processString(inputString):
    sentences = 0;
    letters = 0;
    words = 0;

    for letter in inputString:
        if (letter == '.' or letter == '!' or letter == '?'):
            sentences += 1
        elif re.search("^[a-zA-Z]$", letter):
            letters += 1
        elif letter == ' ':
            words += 1
        else:
            pass

    # final word wont have a space
    words += 1

    gradeLevel = calculateGradeLevel(words, letters, sentences)
    displayGradeLevel(gradeLevel)

def calculateGradeLevel(words, letters, sentences):
    # L = number of letters per 100 word
    # S = number of sentences per 100 words
    L = 0
    S = 0

    L = 100 * letters / words
    S = 100 * sentences / words

    # print("Number of Characters per 100 words =", L)
    # print("Number of sentences per 100 words =", S)

    gradeLevel = 0.0588 * L - 0.296 * S - 15.8

    return int(round(gradeLevel));

def displayGradeLevel(gradeLevel):
    if (gradeLevel < 1):
        print("Before Grade1")
    elif (gradeLevel < 16):
        print("Grade", gradeLevel);
    else:
        print("Grade 16+")

main()