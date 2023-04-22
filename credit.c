#include <cs50.h>
#include <stdio.h>

/*Created by Luis Vargas, February 2nd, 2023
  This is a problem from Harvard's CS50 programming course
  
  The specific problem is:
  
  In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf)
  whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some
  tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less.
  For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and
  that it won’t have leading zeroes. But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input.*/

long get_card(void); //Declaring functions used in main
int splitter(int X);
int summarize(int first, int second, int third, int four, int five, int six, int seven, int eight, int nine
              , int ten, int eleven, int twelve, int thirteen, int fourteen, int fifteen, int sixteen);

int main(void)
{
    long card = get_card(); // Getting the card number

    //Starting to split the numbers
    int first = card % 10;
    int second = (card % 100) / 10;
    int third = (card % 1000) / 100;
    int four = (card % 10000) / 1000;
    int five = (card % 100000) / 10000;
    int six = (card % 1000000) / 100000;
    int seven = (card % 10000000) / 1000000;
    int eight = (card % 100000000) / 10000000;
    int nine = (card % 1000000000) / 100000000;
    int ten = (card % 10000000000) / 1000000000;
    int eleven = (card % 100000000000) / 10000000000;
    int twelve = (card % 1000000000000) / 100000000000;
    int thirteen = (card % 10000000000000) / 1000000000000;
    int fourteen = (card % 100000000000000) / 10000000000000;
    int fifteen = (card % 1000000000000000) / 100000000000000;
    int sixteen = (card % 10000000000000000) / 1000000000000000;
    //Finish splitting the numbers

    int legit = summarize(first, second, third, four, five, six, seven, eight, //Verifying the validity of the card
                          nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen);
    if (legit == 0)
    {
        if (sixteen == 0 && fifteen == 3 && (fourteen == 4 || fourteen == 7)) //Checking if is American Express
        {
            printf("AMEX\n");
        }
        else if (sixteen == 5 && (fifteen == 1 || fifteen == 2 || fifteen == 3 || fifteen == 4 || fifteen == 5)) //Checking if is Mastercard
        {
            printf("MASTERCARD\n");
        }
        else if ((sixteen == 0 && thirteen == 4) || sixteen == 4) //Checking if is Visa
        {
            printf("VISA\n");
        }
        else //Printing invalid because is not applicable
        {
            printf("INVALID\n");
        }
    }
}

long get_card()
{
    long card = get_long("What is the card number\n"); //Asking for user input
    if (card < 1000000000000 || card > 9999999999999999)
    {
        return 0;
    }
    else
    {
        return card;
    }
}

int summarize(int first, int second, int third, int four, int five, int six, int seven, int eight, int nine
              , int ten, int eleven, int twelve, int thirteen, int fourteen, int fifteen, int sixteen)
{
    //Multiplying every other number by 2
    second = second * 2;
    four = four * 2;
    six = six * 2;
    eight = eight * 2;
    ten = ten * 2;
    twelve = twelve * 2;
    fourteen = fourteen * 2;
    sixteen = sixteen * 2;
    //Dividing the numbers in units if bigger than 9
    second = splitter(second);
    four = splitter(four);
    six = splitter(six);
    eight = splitter(eight);
    ten = splitter(ten);
    twelve = splitter(twelve);
    fourteen = splitter(fourteen);
    sixteen = splitter(sixteen);
    int SUM = first + second + third + four + five + six + seven + eight + nine + ten
              + eleven + twelve + thirteen + fourteen + fifteen + sixteen; //Summing everything together
    int legit = SUM % 10; //Verifying that the card is valid
    if (legit == 0)
    {
        return legit;
    }
    else
    {
        printf("INVALID\n");
    }
    return 1;
}

int splitter(int X)
{
    if (X > 9)
    {
        X = (X / 10) + (X % 10);
    }
    return X;
}
