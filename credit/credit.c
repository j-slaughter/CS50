#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for credit card number
    long cc_number = get_long("Number: ");

    // Luhn's Algorithm: Multiply every other digit by 2, starting with second-to-last digit. Sum the products digits.
    // Luhn's Algorithm: Add the sum to the sum of the digits that weren't multiplied
    long number = cc_number;
    int sum_add = 0;
    int sum_multiply = 0;
    int x;
    int y;

    while (number > 0)
    {
        // Get last digit and add to non-multiplied sum
        sum_add += number % 10;
        number = number / 10;

        // Get second-to-last digit and multiply by 2
        x = (number % 10) * 2;
        // Check if product has multiple digits
        if (x > 9)
        {
            y = x % 10;
            x = (x / 10) % 10;
            sum_multiply += (x + y);
        }
        else
        {
            sum_multiply += x;
        }
        number = number / 10;
    }

    // Luhn's Algorithm: If the total's last digit is 0 (total modulo 10 == 0) than it is valid
    int checksum = sum_add + sum_multiply;
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculate length of number
    long n = cc_number;
    int length = 0;
    do
    {
        n = n / 10;
        length++;

    }
    while (n > 0);

    // Determine starting numbers
    do
    {
        cc_number = cc_number / 10;
    }
    while (cc_number >= 100);

    int digit1 = cc_number / 10;
    int digit2 = cc_number % 10;

    // American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13 and 16-digit numbers
    // American Express numbers start with 34 or 37
    // MasterCard numbers start with 51-55
    // Visa numbers start with 4
    if ((length == 15) && (cc_number == 34 || cc_number == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    else if ((length == 13 || length == 16) && (digit1 == 4))
    {
        printf("VISA\n");
        return 0;
    }
    else if ((length == 16) && (50 < cc_number && cc_number < 56))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
