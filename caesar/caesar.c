#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    //Initialization of variables
    bool f;
    int j;
    //check for single command-line argument 
    if (argc == 2)
    {
        // loop to iterate over each character of command-line argument
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // check if command-line argument is a digit
            if (isdigit(argv[1][i]))
            {
                f = true;
            }
            else
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
    // convert command-line argument to integer if it is a digit
    if (f == true)
    {
        j = atoi(argv[1]);
    }
    // prompt user for text to encrypt
    string plain = get_string("plaintext: ");
    //iterate over each character of inputted text
    for (int x = 0, z = strlen(plain); x < z ; x++)
    {
        // encrypt uppercase letters
        if (isupper(plain[x]))
        {
            plain[x] = plain[x] - 65;
            plain[x] = (plain[x] + j) % 26;
            plain[x] = plain[x] + 65;
        }
        // encrypt lowercase letters
        else if (islower(plain[x]))
        {
            plain[x] = plain[x] - 97;
            plain[x] = (plain[x] + j) % 26;
            plain[x] = plain[x] + 97;
        }
        // leave numbers and other symbols as-is
        else
        {
            plain[x] = plain[x];
        }
       
    }
    // print out encrypted text
    printf("ciphertext: %s\n", plain);
    return 0;
}