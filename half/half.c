// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // Calculate tax dollar amount
    float t = bill * (tax / 100);
    // Calculate bill + tax dollar amount
    t = bill + t;
    // Calculate tip dollar amount
    float c = t * ((float) tip / 100);
    // Calculate the total + tip amount
    t = t + c;
    // Split the total
    float split = t / 2;
    return split;
}
