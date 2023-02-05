// Header files
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Decleration and Assignment of variables
    int letters = 0;
    int f = 0, words;
    int sentences = 0;
    string text = get_string("Text: ");
    
    //Loop to get elements of string "text"  
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        // Conditional statement to calculate number of letters in string "text"
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
       
        // Conditional statement to calculate number of words in string "text"
        if (text[i] == ' ' && text[i + 1] != ' ')
        {
            f++;
        }
       
        // Conditional statement to calculate number of sentences in string "text"
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    // Some other variable declaretion and assignment
    words = f + 1;
    float l, s, index;
    int x;
    // Calculation of variables
    l = ((float)letters * 100) / (float)words;
    s = ((float)sentences * 100) / (float)words;
    index = 0.0588 * l - 0.296 * s - 15.8;
    x = round(index);
    // Conditional statement to determine output 
    if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }
}