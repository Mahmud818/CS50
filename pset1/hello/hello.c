#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get input from user 
    string name = get_string("What is your name?\n");
    // print out hello, user's input!
    printf("hello, %s!\n ", name);
}