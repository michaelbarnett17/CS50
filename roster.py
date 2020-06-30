import sys
import csv
from cs50 import SQL

def main():
    db = SQL("sqlite:///students.db")
    house = sys.argv[1]

    if (len(sys.argv) != 2):
        print("enter 1 command line argument")
        return 1

    list = db.execute("select first, middle, last, house, birth from students where house = ? order by last", house)

    for item in list:
        print(item['first'], item['last'], 'born', item['birth'])

main()