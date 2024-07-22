#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// declare calculateGrade function
float calculateGrade(string);

// declare printGrade function
void printGrade(float);

int main(void)
{
    // get the text from the user
    string text = get_string("Text: ");

    // call calculateGrade function
    float gradeIndex = calculateGrade(text);

    // call printGrade function
    printGrade(gradeIndex);
}


// define function that calculate grade & output it
float calculateGrade(string text)
{
    // declare as float not int to avoid truncation of avg result when divided (int / float = int) 
    float wordsCount = 1, lettersCount = 0, sentencesCount = 0;
    // declare wordsCount, lettersCount, lettersAvg, sentencesCount, sentencesAvg
    float lettersAvg = 0.00, sentencesAvg = 0.00;
    float index;

    // loop through the text
    for (int i = 0; i < strlen(text); i++)
    {
        // increment letterCount if it's a letter (using ctype library)
        if (isalpha(text[i]))
        {
            lettersCount += 1;
        }
        // if there is a space (check ascii decimal value) incerment wordCount
        if (text[i] == 32)
        {
            wordsCount += 1;
        }
        // if there is (., !, ?) increment sentencesCount
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentencesCount += 1;
        }
    }

    // calculate grade based on Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    lettersAvg = lettersCount / wordsCount * 100;
    sentencesAvg = sentencesCount / wordsCount * 100;
    index = 0.0588 * lettersAvg - 0.296 * sentencesAvg - 15.8;

    return index;
}


// define printGrade function that gets gradeIndex and prints grade level
void printGrade(float gradeIndex)
{
    // round gradeIndex to the nearest integer
    int gradeInt = round(gradeIndex);

    if (gradeInt < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeInt == 16 || gradeInt > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeInt);
    }
}