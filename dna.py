import csv
import sys

def main():

    cvsFileInfo = processCsvFile()
    strTypes = cvsFileInfo[0]
    persons = cvsFileInfo[1]
    sequenceMaxes = processSequence(strTypes)

    #print(persons)
    #print(sequenceMaxes)

    print(matchSequenceMaxesToPerson(sequenceMaxes, persons, strTypes))

def matchSequenceMaxesToPerson(sequenceMaxes, persons, strTypes):
    personCount = 0
    for person in persons:
        strTypeCount = 0
        for st in strTypes:
            if person.get(st) == sequenceMaxes.get(st):
                strTypeCount += 1
                if strTypeCount == len(strTypes):
                    return person.get('name')
                else:
                    pass
            else:
                pass
    return "No match"

def processSequence(strTypes):
    sequence = sys.argv[2]

    sequenceMaxes = {}

    # https://stackoverflow.com/questions/8369219/how-to-read-a-text-file-into-a-string-variable-and-strip-newlines
    with open (sequence, "r") as myfile:
        personSequence = myfile.readlines()[0]

    for st in strTypes:
        sequenceMaxes[st] = countMaxRepeats(st, personSequence)

    return sequenceMaxes

def countMaxRepeats(st, personSequence):
    #print("Max repeats for str", st)
    overallRepeatCount = 0
    repeatCount = 0

    i = 0
    while(i < len(personSequence) - len(st)):

        if(st == personSequence[i: i + len(st)]):
            repeatCount += 1
            if repeatCount > overallRepeatCount:
                overallRepeatCount = repeatCount
            i += len(st)
        else:
            if repeatCount > overallRepeatCount:
                overallRepeatCount = repeatCount
            repeatCount = 0
            i += 1
    return overallRepeatCount

def processCsvFile():
    database = sys.argv[1]

    # read csv file (use reader or dict reader)
    with open(database, newline='') as csvfile:
        personReader = csv.reader(csvfile, delimiter=' ')
        return processPersonReaderRows(personReader)

def processPersonReaderRows(personReader):
    strTypes = []
    persons = []

    rowCount = 0
    for row in personReader:
        if rowCount == 0:
            strTypes = populateStrTypes(row, strTypes)
            rowCount += 1
        else:
            tempPerson = processPersonRow(row, persons, strTypes)
            persons.append(tempPerson)
            rowCount += 1

    return [strTypes, persons]

def populateStrTypes(row, strTypes):
    rowString = ''.join(row)
    strList = rowString.split (",")
    for item in strList:
        if not item == 'name':
            strTypes.append(item)
    return strTypes

def processPersonRow(row, persons, strTypes):
    rowString = ''.join(row)
    personList = rowString.split (",")

    name = personList[0]
    personList.pop(0)
    strCountList = personList
    strCountList = [int(i) for i in strCountList]

    tempPerson = {'name' : name}

    # https://stackoverflow.com/questions/1919044/is-there-a-better-way-to-iterate-over-two-lists-getting-one-element-from-each-l
    for strType, strCount in zip(strTypes, strCountList):
        tempPerson[strType] = strCount

    return tempPerson

main()