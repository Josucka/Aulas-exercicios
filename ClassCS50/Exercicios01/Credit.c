#include <stdio.h>
#include <cs50.h>

// Luhn's Algorithm

int main(void)
{
    long cardNumber = get_long("Please, enter your card number: ");
    int sum1 = 0, num = 0, remainder = 0, sum2 = 0;
    long temp = cardNumber;

    while (temp > 0)
    {
        num = ((temp / 10) % 10) * 2;
        while (num > 0)
        {
            remainder = num % 10;
            sum1 += remainder;
            num /= 10;
        }
        temp /= 100;
    }

    remainder = 0;
    temp = cardNumber;

    while (temp > 0)
    {
        remainder = temp % 10;
        sum2 += remainder;
        temp /= 100;
    }

    ((sum1 + sum2) % 10) == 0 ? printf("Valid\n") : printf("Invalid\n");
    return 0;
}