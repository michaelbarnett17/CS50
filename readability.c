#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
double calculateGradeLevel(int characters, int words, int sentences);
void displayGradeLevel(double gradeLevel);

int main(void)
{
    //DEBUG
    //string input = "A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.";

    string input = get_string("Enter text: ");
    double gradeLevel;
    int characters = 0;
    int sentences = 0;
    int words = 0;


    for (int i = 0; i < strlen(input); i++)
    {
        char currentChar = input[i];

        if (currentChar == '.' || currentChar == '!' || currentChar == '?')
        {
            sentences++;
        }

        if (122 >= currentChar && currentChar >= 65)
        {
            characters++;
        }

        if (currentChar == ' ')
        {
            words++;
        }


    }
    //Final word won't have a space;
    words++;

    //DEBUG
    //printf("Number of Characters = %i\n", characters);
    //printf("Number of Words = %i\n", words);
    //printf("Number of Sentences = %i\n", sentences);

    displayGradeLevel(calculateGradeLevel(characters, words, sentences));


}

double calculateGradeLevel(int characters, int words, int sentences)
{
    //DEBUG
    // L = number of letters per 100 word
    // S = number of sentences per 100 words
    double L;
    double S = 0;

    L = (double) 100 * characters / words;
    S = (double) 100 * sentences / words;

    //DEBUG
    //printf("Number of Characters per 100 words = %f\n", L);
    //printf("Number of sentences per 100 words = %f\n", S);

    double  gradeLevel = 0.0588 * L - 0.296 * S - 15.8;

    //DEBUG
    //printf("Grade Level = %f", gradeLevel);

    return gradeLevel;
}

void displayGradeLevel(double gradeLevel)
{
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel < 16)
    {
        printf("Grade %i\n", (int) round(gradeLevel));
    }
    else
    {
        printf("Grade 16+\n");
    }
}