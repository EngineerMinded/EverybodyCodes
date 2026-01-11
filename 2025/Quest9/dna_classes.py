class DNA:
    def __init__(self, strand, number):
        self.strand = strand    
        self.number = number

class DNAGROUP:
    def __init__(self, ):
        self.dnaGroup = []

    def addDNA(self, dna):
        self.dnaGroup.append(dna)
    
    def dnaExists(self, dna):
        for d in self.dnaGroup:
            if d.strand == dna.strand and d.number == dna.number :
                return True
        return False
    
    def addDNAGROUP(self, otherGroup):
        for d in otherGroup.dnaGroup:
            if not self.dnaExists(d):
                self.addDNA(d)  

    def getTotalNumber(self):
        total = 0
        for d in  range(len(self.dnaGroup)):
            total += int(self.dnaGroup[d].number)
        return total
    
    def getSizeOfGroup(self):
        return len(self.dnaGroup)   