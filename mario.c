#include <cs50.h>
#include <stdio.h>

/*Created by Luis Vargas, February 2nd, 2023
This is part of Harvard's CS50 programming course*/

int get_height(void); //Declaring functions used in main
void spaces(int i, int j);
void hashtags(int i);

int main(void)
{
    int h = get_height(); //Getting the height of the pyramids from the user
    for (int i = 0; i < h; i++)
    {
        spaces(i, h); //Printing the spaces
        hashtags(i); //Printing the hashtags
        printf("  "); //Printing the middle space
        hashtags(i); //Printing the hashtags
        printf("\n"); //Printing the next line
    }
}

int get_height(void) //Getting the high from the user
{
    int height;
    do
    {
        height = get_int("Tell me a number from 1 to 8: ");
    }
    while (height < 1 || height > 8); //Checking that it is a valid number
    return height;
}

void spaces(int i, int j)  //Printing the spaces
{
    for (int k = j - 1; k > i; k--)
    {
        printf(" ");
    }
}

void hashtags(int i)  //Printing the columns
{
    for (int j = 0; j <= i; j++)
    {
        printf("#");
    }
}
