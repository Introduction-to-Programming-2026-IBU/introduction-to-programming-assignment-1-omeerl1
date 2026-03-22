#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    // Ask how much change is owed (in cents)
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickels = cents / 5;
    cents %= 5;

    int pennies = cents;

    // Sum all coins
    int total_coins = quarters + dimes + nickels + pennies;
    printf("%i\n", total_coins);
}
