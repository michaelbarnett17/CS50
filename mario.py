from cs50 import get_int

def main():
    height = getValidInt()

    for row in range(height):
        printSideSpaces(height, row)
        printPoundSigns(height, row)
        printMiddleSpaces()
        printPoundSigns(height, row)
        print("")


def printMiddleSpaces():
    print("  ", end="")

def getValidInt():
   while True:
        height = get_int("Height: ")
        if 0 < height and height < 9:
            return height

def printSideSpaces(height, row):
    for col in range(height - row - 1):
        print(" ", end="")

def printPoundSigns(height, row):
    for col in range(row + 1):
        print("#", end="")

main()