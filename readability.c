#include <cs50.h>
#include <stdio.h>

// declare gradeIndex to use it with the functions  
// declare calculateGrade function
// delcare printGrade function

int main(void)
{
    // get the text from the user

    // call calculateGrade function

    // call printGrade function
}


// define function that calculate grade & output it
    // declare wordCount, letterCount, lettersAvg, sentencesCount, sentencesAvg 
    // loop through the text
        // increment letterCount
        // if there is no uppercase or lower case letter incerment wordCount
        // if there is (., !, ?) increment sentencesCount
    // calculate grade based on Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8


// define function that gets gradeIndex and prints grade level
    // if gradeIndex less than print Grade 1
    // else if gradeIndex is 16 or higher print Grade 16+
    // else print grade level rounded to the nearest integer