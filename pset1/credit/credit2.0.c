#include <cs50.h>
#include <stdio.h>
#include <math.h>

//function declaration
int greater(int x);
int ind_num(long x, int y);

int main(void)
{
    // declaration and assignment of variables
    long n = get_long("input card number\n");
    int lenght = 0, a, b, c, d, e, f, g, h, i, k;
    int n1 = ind_num(n, 1);
    int n2 = ind_num(n, 2);
    int n3 = ind_num(n, 3);
    int n4 = ind_num(n, 4);
    int n5 = ind_num(n, 5);
    int n6 = ind_num(n, 6);
    int n7 = ind_num(n, 7);
    int n8 = ind_num(n, 8);
    int n9 = ind_num(n, 9);
    int n10 = ind_num(n, 10);
    int n11 = ind_num(n, 11);
    int n12 = ind_num(n, 12);
    int n13 = ind_num(n, 13);
    int n14 = ind_num(n, 14);
    int n15 = ind_num(n, 15);
    int n16 = ind_num(n, 16);
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
int ind_num(long x, int y)
{
    long v = x / pow(10, (y-1));
    int w = v % 10;
    return w;
}