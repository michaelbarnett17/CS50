from cs50 import get_float

def main():
    cents = 100 * getCash()
    print(calculateCoinCount(cents))

def getCash():
    while True:
        cash = get_float("Changed owed: ")
        if cash > 0:
            break;
    return cash

def calculateCoinCount(cents):
    coinCount = 0

    while cents > 0:
        if cents - 25 >= 0:
            cents = cents - 25
            coinCount += 1
        elif cents - 10 >= 0:
            cents = cents - 10
            coinCount += 1
        elif cents - 5 >= 0:
            cents = cents - 5
            coinCount += 1
        else:
            cents = cents - 1
            coinCount += 1

    return coinCount

main()