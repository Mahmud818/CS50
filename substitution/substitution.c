#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //variable assignment
    bool f;
    //check for one command-line argument
    if (argc == 2)
    {
        // iterate over each character of command-line argument(key)
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // check if key contains alphabets alone
            if (isalpha(argv[1][i]))
            {
                for (int j = 0; j < n; j++)
                {
                    for (int c = j + 1 ; c < n; c++)
                    {
                        //check for duplicate letters
                        if (argv[1][j] != argv[1][c])
                        {
                            f = true;
                        }
                        // print error message if letters are duplicated
                        else
                        {
                            printf("characters should not be repeated\n");
                            return 1;
                        }
                    }
                }
            }
            // print error message if key contains other character
            else
            {
                printf("key must only contain alphabetic characters\n");
                return 1;
            }
            // print error message if key is not 26 characters long
            if (n != 26)
            {
                printf("key must contain 26 characters.\n");
                return 1;
            }
        }
    }
    //print errror message if command-line argument are not 2
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    if (f == true)
    {
        //convert uppercase key characters to lowercase
        for (int w = 0,  p = strlen(argv[1]); w < p; w++)
        {
            if (isupper(argv[1][w]))
            {
                argv[1][w] = tolower(argv[1][w]);
            }
            else
            {
                argv[1][w] = argv[1][w];
            }
        }
        //accept plaintext input from user
        string plain = get_string("plaintext: ");
        //print ciphertext output
        printf("ciphertext: ");
        for (int k = 0, m = strlen(plain); k < m; k++)
        {
            //encrypt lowercase plaintext characters to lowercase ciphertext characters
            if (islower(plain[k]))
            {
                int d = plain[k] - 97;
                char z = argv[1][d];
                printf("%c", z);
            }
            //encrypt uppercase plaintext characters to uppercase ciphertext characters
            else if (isupper(plain[k]))
            {
                plain[k] = tolower(plain[k]);
                int d = plain[k] - 97;
                char z = toupper(argv[1][d]);
                printf("%c", z);
            }
            //leave non alphabetic key characters as-is
            else
            {
                char z = plain[k];
                printf("%c", z);
            }


        }
        //print new line
        printf("\n");
        //end program
        return 0;
    }

}