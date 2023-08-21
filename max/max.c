// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    // Initialize highest value to first element in array
    int highest = array[0];
    for (int i = 0; i < n; i++)
    {
        //Compare each value to find the highest value element
        if (array[i] > highest)
        {
            highest = array[i];
        }
    }
    // Return highest value
    return highest;
}
