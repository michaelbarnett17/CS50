import sys
import csv
from cs50 import SQL

def main():
    db = SQL("sqlite:///students.db")

    if (len(sys.argv) != 2):
        print("enter 1 command line argument")
        return 1

    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            fullName = row['name']
            house = row['house']
            birth = row['birth']
            insertRow(db, fullName, house, birth)

def insertRow(db, fullName, house, birth):
    fullNameList = fullName.split()
    if (len(fullNameList) == 2):
        firstName = fullNameList[0]
        lastName = fullNameList[1]
        db.execute("insert into students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                           firstName, None, lastName, house, birth)
    elif (len(fullNameList) == 3):
        firstName = fullNameList[0]
        middleName = fullNameList[1]
        lastName = fullNameList[2]
        db.execute("insert into students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   firstName, middleName, lastName, house, birth)

main()