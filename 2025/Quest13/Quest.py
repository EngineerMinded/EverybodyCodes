'''
    Wayne Mack
    Everybody Codes
    Quest 13
'''
# Read numbers from a file
def read_number_groups(filename, isPart3 = False):
    numbers = []
    with open(filename, "r") as f:
        for line in f:
            parts = line.strip().split(",")
            for part in parts:
                part = part.strip()
                if "-" in part:
                    if not isPart3:
                        start, end = part.split("-")
                        start, end = int(start), int(end)
                        group = []
                        for n in range(start, end + 1):
                            group.append(n)
                        numbers.append(group)
                    else:
                        numbers.append(part)
                elif part.isdigit():
                    numbers.append(int(part))
                # ignore invalid tokens silently
    return numbers

def parse_numbers_into_sequence(numbers , isPart3 = False):
    list = []
    if not isPart3:
        list.append(1)
    else:
        list.append("1-1")
    secondlist = []
    for i in range(len(numbers)):
        if (i % 2) == 0:
            if (not isPart3) and isinstance(numbers[i], type([])):
                for n in numbers[i]:
                    list.append(n)
            else:
                list.append(numbers[i])
        else:
            if (not isPart3) and isinstance(numbers[i], type([])):
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

    def diffFromString(s):
        #Remove spaces, split on '-', convert to integers
        a, b = s.split('-')
        return abs(int(a) - int(b)) + 1  # +1 to include both endpoints
    
    def getTotalCount(listOfNumbers):
        total = 0
        for item in listOfNumbers:
            total += diffFromString(item)
        return total

    def getNumberInGroup(group, position):

        a, b = group.replace(" ", "").split('-')
        return int(b) - position  
    
    turns = turns % getTotalCount(listOfNumbers)
    i = 0
    while turns > diffFromString(listOfNumbers[i]):
        turns -= diffFromString(listOfNumbers[i])
        i += 1
    if i >= len(listOfNumbers):
        return -1 # Out of bounds, should not happen
    return getNumberInGroup(listOfNumbers[i], turns)

# PART ONE
examplea = read_number_groups("example1.txt")
examplea = parse_numbers_into_sequence(examplea)
print ("Example 1: " + str(getValueAfterTurns(examplea, 2025)))

part1 = read_number_groups("part1.txt")
part1 = parse_numbers_into_sequence(part1)
print ("Part 1: " + str( getValueAfterTurns(part1, 2025)))

# PART TWO
exampleb = read_number_groups("example2.txt")
exampleb = parse_numbers_into_sequence(exampleb)
print ("Example 2: " + str(getValueAfterTurns(exampleb, 20252025)))

part2 = read_number_groups("part2.txt")
part2 = parse_numbers_into_sequence(part2)
print ("Part 2: " + str(getValueAfterTurns(part2, 20252025)))

part2 = read_number_groups("part2.txt", True)
part2 = parse_numbers_into_sequence(part2, True)
print ("Part 2 with new function: " + str(getValueAfterTurnsIncludingLists(part2, 20252025)))

# PART THREE
part3 = read_number_groups("part3.txt", True)
part3 = parse_numbers_into_sequence(part3, True)
print ("Part 3: " + str(getValueAfterTurnsIncludingLists(part3, 202520252025)))

