#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    long number;

    do
    {
        number = get_long("Card number: ");
    }
    while (number < 0);

    // count the card number digits
    long temp = number;
    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }

    // check if the cardnumber is valid or not
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID card length\n");
    }
    else
    {
        // luhns algoritm
        long cc = number;
        int sum1 = 0;
        int sum2 = 0;
        int counter = 0;
        while (cc > 0)
        {
            int digit = cc % 10;  // This gives me the first digit from right to left.
            if (counter % 2 != 0) // to check if the counter is even or odd. The counter starts at 0.
            {
                // counter is odd
                digit = digit * 2;
                sum1 = sum1 + digit / 10 + digit % 10; // if digit is a two digit number this will seperate it if it is a double digit when you the add sum.
            }
            else // counter is even
            {
                sum2 = sum2 + digit;
            }
            cc = cc / 10;
            counter++;
        }
        int sum = sum1 + sum2; // here i take the sum1 and sum2 and combine them
        if (sum % 10 == 0)     // if sum end with 0 then credit card is correct
        {
            printf("Valid\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }

    // define wich card is being used
    long card_id = number;
    do // We only want the first few digits in Card number to check what card it is
    {
        card_id = card_id / 10;
    }
    while (card_id >= 100);

    if (card_id == 34 || card_id == 37) // check if the card is an american express
    {
        printf("American Express\n");
    }
    else if (card_id >= 51 && card_id <= 55) // check if the card is a master card
    {
        printf("Mastercard\n");
    }
    else if (card_id / 10 == 4) // check if the card is visa
    {
        printf("Visa\n");
    }
    else
    {
        printf("Unknown card\n");
    }
}
