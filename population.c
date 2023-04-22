#include <cs50.h>
#include <stdio.h>

/*Created by Luis Vargas, February 2nd, 2023
  This is a problem from the CS50 Harvard Course
 
The problem that this program aims to solve is the following:
Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

For example, if we were to start with n = 1200 llamas, then in the first year, 1200 / 3 = 400 new llamas would be born and 1200 / 4 = 300 llamas would pass away.
At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.
To try another example, if we were to start with n = 1000 llamas, at the end of the year, we would have 1000 / 3 = 333.33 new llamas.
We can’t have a decimal portion of a llama, though, so we’ll truncate the decimal to get 333 new llamas born.
1000 / 4 = 250 llamas will pass away, so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.*/


int get_population(void);
int get_end_population(int initial);
int years(int initial, int final);

int main(void)
{
    // Prompt for start size
    int n = get_population();
    // Prompt for end size
    int p = get_end_population(n);
    // Calculate number of years until we reach threshold
    int i = years(n, p);
    // Print number of years
    printf("Years: %i\n", i);
}

int get_population(void)
{
    int n;
    do
    {
        n = get_int("Population size: ");
    }
    while (n < 9); // Makes sure that the initial population is valid
    return n;
}

int get_end_population(int initial)
{
    int n;
    do
    {
        n = get_int("Population end size: "); //Makes sure that the final population is valid
    }
    while (n < initial);
    return n;
}

int years(int initial, int final)
{
    int i = 0;
    for (; initial < final; i++)
    {
        initial = initial + initial / 3 - initial /
                  4; //Calculates the amount of years necessary to get to the desired population considering the initial one
    }
    return i;
}
