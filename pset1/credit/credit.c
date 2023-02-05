#include <cs50.h>
#include <stdio.h>
#include <math.h>

//function declaration
int greater(int x);

int main(void)
{
    // declaration and assignment of variables
    long n = get_long("input card number\n");
    int lenght = 0, a, b, c, d, e, f, g, h, i, k;
    int n1 = n % 10;
    int n2 = (n / 10) % 10;
    int n3 = (n / 100) % 10;
    int n4 = (n / 1000) % 10;
    int n5 = (n / 10000) % 10;
    int n6 = (n / 100000) % 10;
    int n7 = (n / 1000000) % 10;
    int n8 = (n / 10000000) % 10;
    int n9 = (n / 100000000) % 10;
    int n10 = (n / 1000000000) % 10;
    int n11 = (n / 10000000000) % 10;
    int n12 = (n / 100000000000) % 10;
    int n13 = (n / 1000000000000) % 10;
    int n14 = (n / 10000000000000) % 10;
    int n15 = (n / 100000000000000) % 10;
    int n16 = (n / 1000000000000000) % 10;
    // function call for variable assignment
    a = greater(n2);
    b = greater(n4);
    c = greater(n6);
    d = greater(n8);
    e = greater(n10);
    f = greater(n12);
    g = greater(n14);
    h = greater(n16);
    i = a + b + c + d + e + f + g + h;
    k = i + n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15;
   
    // calculate lenght of input
    while (n != 0)
    {
        n = n / 10;
        lenght++;
    }
    
    // check if k's last digit is 0
    if (k % 10 == 0)
    {
        //check if lenght of input is 16 or 13 and if it starts with 4, printing VISA if the condition is met
        if ((lenght == 16 || lenght == 13) && (n16 == 4 || n13 == 4))
        {
            printf("VISA\n");
        }
        // or check if lenght of input is 15 and if it starts with 34 or 37, printing AMEX if the condition is met
        else if ((lenght == 15) && (n15 == 3 && (n14 == 4 || n14 == 7)))
        {
            printf("AMEX\n");
        }
        // or check if lenght of input is 16 and if it starts with 51, 52, 53, 54 or 55, printing MASTERCARD if the condition is met
        else if ((lenght == 16) && (n16 == 5 && (n15 == 1 || n15 == 2 || n15 == 3 || n15 == 4 || n15 == 5)))
        {
            printf("MASTERCARD\n");
        }
        // if above conditions are not met print INVALID
        else 
        {
            printf("INVALID\n");
        }
    }
    // if k's last digit isn't print INVALID
    else
    {
        printf("INVALID\n");
    }
}
    
// function to sum the individual digits of a number greater than 9
int greater(int x)
{
    int j; 
    int m = x * 2;
    if (m > 9)
    {
        j = (m % 10) + ((m / 10) % 10);
    }
    else
    {
        j = m;
    }
    return j;
}
