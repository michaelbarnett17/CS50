import re
from cs50 import get_string

AMEX = "^3[47]\d{13}$"
MASTERCARD = "^5[15]\d{14}$"
VISA = "^4[09]\d{11}(\d{3})?$"

def main():

    cardString = get_string("enter your credit card number: ")
    processCardNumber(cardString)

def processCardNumber(cardString):
    cardType = ""

    if re.search(AMEX, cardString):
        cardType = "AMEX"
    elif re.search(MASTERCARD, cardString):
        cardType = "MASTERCARD"
    elif re.search(VISA, cardString):
        cardType = "VISA"
    else:
        pass

    if runLuhnsAlogrithm(cardString) == 1 and cardType != "":
        print(cardType)
    else:
        print("INVALID")

def runLuhnsAlogrithm(cardString):
    cardStringReverse = cardString[::-1]
    sumOfProducts = 0
    sumOfOtherDigits = 0
    finalSum = 0

    index = 0
    for digit in cardStringReverse:
        if index % 2 == 0:
            sumOfOtherDigits += int(digit)

        currentDoubleDigit = getEveryOtherDigitTimes2(digit, index)
        sumOfProducts = processDoubleDigits(sumOfProducts, currentDoubleDigit)
        index += 1

    finalSum = sumOfProducts + sumOfOtherDigits

    if (finalSum % 10 == 0):
        return 1
    else:
        return 0

def getEveryOtherDigitTimes2(digit, index):
    if (index + 1) % 2 == 0:
        digit = int(digit)
        digit *= 2
        #print("Even digit dobuled", digit)
        return digit
    #example: don't process B's ABABABAB
    else:
        return 0

def processDoubleDigits(sumOfProducts, currentDoubleDigit):
    if currentDoubleDigit < 10:
        #print(sumOfProducts)
        sumOfProducts += int(currentDoubleDigit)
    else:
        sumIndividualDigits = 0
        for digit in str(currentDoubleDigit):
            sumOfProducts += int(digit)
    return sumOfProducts

main()