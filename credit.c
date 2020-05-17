#include <stdio.h>
#include <cs50.h>
#include <math.h>

void processAmex34(long input);
void processAmex37(long input);
void processMastercard(long input);
void processVisa13(long input);
void processVisa16(long input);
void processInput(long input, int count);
int getCurrentDigit(long input, int i);
int getEveryOtherDigitTimes2(int i, int currentDigit);
int processDoubledDigits(int sumOfProducts, int currentDoubleDigit);
void processCardNumber(long input);
void displayMesssage(string card, bool isValid);

int main(void)
{
    long input = get_long("enter your credit card number\n");
    processCardNumber(input);
}
void processCardNumber(long input)
{
    //For Amex cards with start with the numbers 34 and 15 digits
    long amexMin34 = 340000000000000;
    long amexMax34 = 349999999999999;

    //For Amex cards with start with the numbers 37 and 15 digits
    long amexMin37 = 370000000000000;
    long amexMax37 = 379999999999999;

    //For MasterCard with 16 digits;
    long mastercardMin = 5100000000000000;
    long mastercardMax = 5599999999999999;

    // For Visa that are 13 digits
    long visaMin13 = 4000000000000;
    long visaMax13 = 4999999999999;

    //For Visa thare are 16 digits
    long visaMin16 = 4000000000000000;
    long visaMax16 = 4999999999999999;

    if (amexMax34 >= input && input >= amexMin34)
    {
        processAmex34(input);
    }
    else if (amexMax37 >= input && input >= amexMin37)
    {
        processAmex37(input);
    }
    else if (mastercardMax >= input && input >= mastercardMin)
    {
         processMastercard(input);
    }
    else if (visaMax13 >= input && input >= visaMin13)
    {
        processVisa13(input);
    }
    else if (visaMax16 >= input && input >= visaMin16)
    {
        processVisa16(input);
    }
    else
    {
        printf("%s", "INVALID\n");
    }
}
bool runLuhnsAlgorithm(long input, int count)
{
    int sumOfProducts = 0;
    int sumOfOtherDigits = 0;
    int finalSum = 0;

    for (int i = 0; i < count; i++)
    {
        int currentDigit = getCurrentDigit(input, i);

        if (i % 2 == 0)
        {
            sumOfOtherDigits += currentDigit;
        }
        //DEBUG
        //printf("%i\n", currentDigit);

        int currentDoubleDigit = getEveryOtherDigitTimes2(i, currentDigit);
        sumOfProducts = processDoubledDigits(sumOfProducts, currentDoubleDigit);
    }
    //DEBUG
    //printf("the sum of products is %i", sumOfProducts);
    //printf("the sum of the other digits is %i", sumOfOtherDigits);
    //printf("the final sum is %i", finalSum);

    finalSum = sumOfProducts + sumOfOtherDigits;

    if (finalSum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
int processDoubledDigits(int sumOfProducts, int currentDoubleDigit)
{
    if (currentDoubleDigit < 10)
    {
        sumOfProducts += currentDoubleDigit;
    }
    else
    {
        int firstDigit;
        int secondDigit;
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                firstDigit = getCurrentDigit(currentDoubleDigit, j);
            }
            if (j == 1)
            {
                secondDigit = getCurrentDigit(currentDoubleDigit, j);
            }
        }
        sumOfProducts += (firstDigit + secondDigit);
    }
    return sumOfProducts;
}
int getEveryOtherDigitTimes2(int i, int currentDigit)
{
    if ((i + 1 ) % 2 == 0)
    {
        currentDigit *= 2;
        //DEBUG
        //printf("%i\n", currentDigit);
        return currentDigit;
    }
    else
    {
        return 0;
    }
}
int getCurrentDigit(long input, int i)
{
    int currentDigit;
    if (i == 0)
    {
        currentDigit = input%10;
        return currentDigit;
    }
    else
    {
        long power = 1;

        for (long j = 0; j < i; j++)
        {
            power *= 10;
        }

        currentDigit = (input / power) % 10;
        return currentDigit;
    }
}
void processAmex34(long input)
{
    bool isValid = runLuhnsAlgorithm(input, 15);
    displayMesssage("AMEX", isValid);
}
void processAmex37(long input)
{
    bool isValid = runLuhnsAlgorithm(input, 15);
    displayMesssage("AMEX", isValid);
}
void processMastercard(long input)
{
    bool isValid = runLuhnsAlgorithm(input, 16);
    displayMesssage("MASTERCARD", isValid);
}
void processVisa13(long input)
{
    bool isValid = runLuhnsAlgorithm(input, 13);
    displayMesssage("VISA", isValid);
}
void processVisa16(long input)
{
    bool isValid = runLuhnsAlgorithm(input, 16);
    displayMesssage("VISA", isValid);
}
void displayMesssage(string card, bool isValid)
{
    if (card && isValid)
    {
        printf("%s\n", card);
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}