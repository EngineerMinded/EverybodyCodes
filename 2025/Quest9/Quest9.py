''' Wayne Mack
    Everybody Codes
    Quest 9             '''

from dna_classes import DNA, DNAGROUP

def findMatches(firstStrand, secondStrand):
    count = 0
    for i in range(len(firstStrand)):
        if firstStrand[i] == secondStrand[i]:
            count += 1
    return count

def read_lines(filename):
    """Read a file and return each line containing only letters."""
    result = []
    dnaValues = []
    number = 0
    with open(filename, "r", encoding="utf-8") as f:
        for line in f:
            cleaned = "".join(ch for ch in line if ch.isalpha())
            numberdigit = "".join(ch for ch in line if ch.isdigit())
            result.append(cleaned)
            d = DNA(cleaned, numberdigit)
            dnaValues.append(d)          
    return dnaValues

def isAChildOfParents(parent1, parent2, child):
    for i in range(len(child.strand)):
        if child.strand[i] != parent1.strand[i] and child.strand[i] != parent2.strand[i]:
            return 0
    return findMatches(child.strand, parent1.strand) * findMatches(child.strand, parent2.strand)

def findAndCalculateChildren(strands):
    total = 0
    for a in range(len(strands)):
        for b in range(len(strands)):
            for c in range(len(strands)):
                if a != b and a != c and b != c:
                    total += isAChildOfParents(strands[a], strands[b], strands[c])
    return total // 2  # Each child counted twice

def mergeDNAGroupswithCommonDNA(groupList):
    merged = []
    while groupList:
        currentGroup = groupList.pop(0)
        hasMerged = True
        while hasMerged:
            hasMerged = False
            for otherGroup in groupList:
                for dna in currentGroup.dnaGroup:
                    if otherGroup.dnaExists(dna):
                        currentGroup.addDNAGROUP(otherGroup)
                        groupList.remove(otherGroup)
                        hasMerged = True
                        break
                if hasMerged:
                    break
        merged.append(currentGroup)
    return merged   

''' practical is not the correct answer'''
def findLargestFamilyGroup(strands):
    dnaGROUP = []
    for a in range(len(strands)):
        for b in range(len(strands)):
            for c in range(len(strands)):
                if a != b and a != c and b != c:
                    total = isAChildOfParents(strands[a], strands[b], strands[c])
                    if total > 0:
                        foundDNA = False
                        for f in dnaGROUP:
                            if f.dnaExists(strands[a]) or f.dnaExists(strands[b]) or f.dnaExists(strands[c]):
                                if not f.dnaExists(strands[a]):
                                    f.addDNA(strands[a])
                                if not f.dnaExists(strands[b]):
                                    f.addDNA(strands[b])
                                if not f.dnaExists(strands[c]):
                                    f.addDNA(strands[c])
                                foundDNA = True
                        if not foundDNA:
                                newGroup = DNAGROUP()
                                newGroup.addDNA(strands[a])
                                newGroup.addDNA(strands[b])
                                newGroup.addDNA(strands[c])
                                dnaGROUP.append(newGroup)
    dnaGROUP = mergeDNAGroupswithCommonDNA(dnaGROUP)
    largestGroupSize = 0
    for g in dnaGROUP:
        if g.getSizeOfGroup() > largestGroupSize:
            largestGroupSize = g.getTotalNumber()
            #print(str(g.getSizeOfGroup()) +  " " + str(largestGroupSize))

    return largestGroupSize
    
# PART ONE
Example1a = "CAAGCGCTAAGTTCGCTGGATGTGTGCCCGCG"
Example1b = "CTTGAATTGGGCCGTTTACCTGGTTTAACCAT"
Example1c = "CTAGCGCTGAGCTGGCTGCCTGGTTGACCGCG"
print ((findMatches(Example1a, Example1c)) * (findMatches(Example1b, Example1c)))
puzzle1a = "TTTCTGCGCGTAGTCGTTCGGAAATACGTCACTCGTGCAGCGGCGTACCATAAGCTACACATGAAGATATGCCGTTCTCGCCACGGTCTCTTGCCGTCCACATATGAGCGGACACTATACTGTCCTCG"
puzzle2b = "CACATCGATAAAACACTAACCCGCGTCCCGAGGCAATGGACTTCAGAGACGTCGGAGGACTGAAGTAATTGGTTGGGTTGTGCTCACGTCATTGAAAGCAGATTGCGAACCGCAATTTCGAAGGTATA"
puzzle2c = "CATATGCGCAAAGCCGTACGGCGCTTCCCCAGGCAATCAGCTTCAGAGACTTAGGTACACTTGAGTAAATGGCGTTGTCGTGCTGGCGTCATTCAATGCAGATTGGGGCGCACAATTTCGAGTCCACG"
print ((findMatches(puzzle1a, puzzle2c)) * (findMatches(puzzle2b, puzzle2c)))

# PART TWO
part2 = 0
strands = read_lines("example2.txt")
print(findAndCalculateChildren(strands))
strands = read_lines("puzzle2.txt")
print(findAndCalculateChildren(strands))

#part THREE
strands = read_lines("example2.txt")
print(findLargestFamilyGroup(strands))
strands = read_lines("example3.txt")
print(findLargestFamilyGroup(strands))
strands = read_lines("puzzle3.1.txt")
print(findLargestFamilyGroup(strands))