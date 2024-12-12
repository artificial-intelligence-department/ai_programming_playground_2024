#include <cs50.h>
#include <stdio.h>

bool luhn_check(long number);
int get_card_type(long number);

int main(void)
{
    long card_number = get_long("Number: ");

    // Validate using Luhn's algorithm
    if (!luhn_check(card_number))
    {
        printf("INVALID\n");
        return 0;
    }
    int card_type = get_card_type(card_number);

    switch (card_type)
    {
        case 1:
            printf("AMEX\n");
            break;
        case 2:
            printf("MASTERCARD\n");
            break;
        case 3:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
            break;
    }
}
bool luhn_check(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9){
                digit = (digit % 10) + (digit / 10);
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10) == 0;
}
int get_card_type(long number)
{
    int length = 0;
    long start = number;

    while (start >= 100)
    {
        start /= 10;
        length++;
    }
    length += 2;

    // Check American Express
    if (length == 15 && (start == 34 || start == 37))
    {
        return 1;
    }

    // Check MasterCard
    if (length == 16 && (start >= 51 && start <= 55))
    {
        return 2;
    }

    // Check Visa
    if ((length == 13 || length == 16) && (start / 10 == 4))
    {
        return 3;
    }
    return 0;
}
