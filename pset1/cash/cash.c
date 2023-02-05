#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initialization of variables
    float d;
    int q = 0;
    int k = 0;
    int n = 0;
    int p = 0;
    // to accept only positive float inputs
    do
    {
        d = get_float("Cash owed: ");
    }
    while (d < 0);
    
    // convert from dollar to cent
    int c;
    c = round(d * 100);
    // loop to calculate highest number of quarters required for change
    while (c >= 25)
    {
        c = c - 25;
        q++;
    }
    // loop to calculate highest number of dimes required for change
    while (c >= 10)
    {
        c = c - 10;
        k++;
    }
    // loop to calculate highest number of nickels required for change
    while (c >= 5)
    {
        c = c - 5;
        n++;
    }
    // loop to calculate highest number of pennys required for change
    while (c >= 1)
    {
        c = c - 1;
        p++;
    }
    // print out the sum of highest number of each coin required for change
    printf("%i\n", q + k + n + p);
}