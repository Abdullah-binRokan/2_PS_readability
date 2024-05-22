#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// declare gradeIndex to use it with the functions
// declare calculateGrade function
float calculateGrade(string text);
// delcare printGrade function

int main(void)
{
    // get the text from the user
    string text = get_string("Text: ");

    // call calculateGrade function
    float gradeIndex = calculateGrade(text);

    // call printGrade function
}


// define function that calculate grade & output it
float calculateGrade(string text)
{
    // declare wordsCount, lettersCount, lettersAvg, sentencesCount, sentencesAvg
    int wordsCount, lettersCount = 0, sentencesCount = 0;
    float lettersAvg = 0, sentencesAvg = 0;

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
    printf("\nlettersCount : %i\n", lettersCount);
    printf("\nwordsCount : %i\n", wordsCount);
    printf("\nsentencesCount : %i\n", sentencesCount);
    printf("\nsentencesAvg : %f\n", sentencesAvg);


    // calculate grade based on Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    lettersAvg = lettersCount / wordsCount * 100;
    sentencesAvg = sentencesCount / wordsCount * 100;
    printf("\nsentencesAvg : %f\n", sentencesAvg);
    printf("\nLAvg: %f     SAvg:  %f", lettersAvg, sentencesAvg);
    printf("\nindex = %f\n", 0.588 * lettersAvg - 0.296 * sentencesAvg - 15.8);
}


// define function that gets gradeIndex and prints grade level
    // if gradeIndex less than print Grade 1
    // else if gradeIndex is 16 or higher print Grade 16+
    // else print grade level rounded to the nearest integer