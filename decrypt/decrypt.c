#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    bool f;
    if (argc == 2)
    {
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                for(int j = 0; j < n; j++)
                {
                    for(int k = j + 1; k < n; k++)
                    {
                        if (argv[1][j]!=argv[1][k])
                        {
                            f = true;
                        }
                        else
                        {
                            printf("key characters must not be repeated\n");
                            return 1;
                        }
                    }
                }
            }
            else
            {
                printf("Key must only contain alphabets\n");
                return 1;
            }
            if (n != 26)
            {
                printf("key must be 26 character long\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./decrypt key!\n");
        return 1;
    }
    string cipher = get_string("input cipher: ");
    printf("plaintext: ");
    int a;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isupper(argv[1][i]))
        {
            argv[1][i]=tolower(argv[1][i]);
        }
    }
    for (int k = 0, j = strlen(cipher); k < j; k++)
    {
        if (isupper(cipher[k]))
        {
            cipher[k]=tolower(cipher[k]);
            for (int w=0 , d = strlen(cipher); w < d; w++)
        {
            if(cipher[k]==argv[1][w])
            {
               a = w;
            }
        }
        printf("%c",a+65);
        }
        else if(islower(cipher[k]))
        {
                for (int w=0 , d = strlen(argv[1]); w < d; w++)
        {
            if(cipher[k]==argv[1][w])
            {
               a = w;
            }
        }
        printf("%c",a+97);

        }
        else
        {
            printf("%c",cipher[k]);
        }
    }
    printf("\n");
    return 0;
}
