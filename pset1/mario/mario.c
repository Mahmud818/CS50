#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for positive integer input between 1 and 8
    int h;
    do
    {
        h = get_int("input a height:\n");
    }
    while (h <= 0 || h > 8);
    // run loop to print right-aligned pyramid of hashes
    for (int i = 1; i <= h; i++)
    {
        // loop to print spaces to right-align the hashes
        for (int j = 1; j <= h - i; j++)
        {
            printf(" ");
        }
        // loop to print hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        // to print gap between adjacent pyramids
        printf("  ");
        // to print right-aligned pyramid
        for (int n = 1; n <= i; n++)
        {
            printf("#");
        }
        // to go to new line
        printf("\n");
    }
    
}
