'''
    Wayne Mack
    Everybody Codes
    Quest 13
'''
# Read numbers from a file
def read_number_groups(filename):
    numbers = []
    with open(filename, "r") as f:
        for line in f:
            parts = line.strip().split(",")
            for part in parts:
                part = part.strip()
                if "-" in part:
                    start, end = part.split("-")
                    start, end = int(start), int(end)
                    group = []
                    for n in range(start, end + 1):
                        group.append(n)
                    numbers.append(group)
                elif part.isdigit():
                    numbers.append(int(part))
                # ignore invalid tokens silently

    return numbers

def parse_numbers_into_sequence(numbers , isPart3 = False):
    list = []
    list.append(1)
    secondlist = []
    for i in range(len(numbers)):
        if (i % 2) == 0:
            if isPart3 and isinstance(numbers[i], type([])):
                for n in numbers[i]:
                    list.append(n)
            else:
                list.append(numbers[i])
        else:
            if isPart3 and isinstance(numbers[i], type([])):
                for n in numbers[i]:
                    secondlist.append(n)
            else:
                secondlist.append(numbers[i])
    for i in range(len(secondlist) - 1, -1, -1):
        list.append(secondlist[i])
    return list

def getValueAfterTurns(listOfNumbers, turns):

    turns = turns % len(listOfNumbers)
    return listOfNumbers[turns]

def getValueAfterTurnsIncludingLists(listOfNumbers, turns):
    address = 0
    while turns > 0:
        if listOfNumbers[address] is list:
            if (len(listOfNumbers[address]) >= turns):
                return listOfNumbers[address][turns - 1]
            else :
                turns = turns - len(listOfNumbers[address])

        else :
            turns = turns - 1

        if address < len(listOfNumbers) - 1:
            address = 0
    return listOfNumbers[address]

examplea = read_number_groups("example1.txt")
examplea = parse_numbers_into_sequence(examplea)
print ("Example 1: " + str(getValueAfterTurns(examplea, 2025)))

part1 = read_number_groups("part1.txt")
part1 = parse_numbers_into_sequence(part1)
print ("Part 1: " + str( getValueAfterTurns(part1, 2025)))

exampleb = read_number_groups("example2.txt")
exampleb = parse_numbers_into_sequence(exampleb)
print ("Example 2: " + str(getValueAfterTurns(exampleb, 20252025)))

part2 = read_number_groups("part2.txt")
part2 = parse_numbers_into_sequence(part2,True)
print ("Part 2: " + str(getValueAfterTurnsIncludingLists(part2, 20252025)))

#part3 = read_number_groups("part3.txt")
#part3 = parse_numbers_into_sequence(part3, True)
#print ("Part 3: " + str(getValueAfterTurns(part3, 202520252025)))

