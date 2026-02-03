'''
    Wayne Mack
    Everybody Codes
    Quest 14

'''

def read_file_to_2d_char_array(filename):
    grid = []
    with open(filename, "r", encoding="utf-8") as f:
        for line in f:
            # Keep the characters, strip the newline
            row = list(line.rstrip("\n"))
            grid.append(row)
    return grid

def partOneConversion(old):
    new = []

    def convertCharacter(old, x, y):
        # check four diagonal neighbors
        count = 0
        directions = [(-1, -1), (-1, 1), (1, -1), (1, 1)]
        for dx, dy in directions:
            if (x + dx >= 0 and x + dx < len(old) and
                y + dy >= 0 and y + dy < len(old[0])):
                if old[x + dx][y + dy] == "#":
                    count += 1
        if old[x][y] == "#":
            if count % 2 == 1:
                return "#"
            else:
                return "."
        else:
            if count % 2 == 0:
                return "#"
            else:
                return "."
    
    for i in range(len(old)):
        newLine = []
        for j in range(len(old[i])):
            newLine.append(convertCharacter(old, i, j))
        new.append(newLine)
    return new

def countOccupied(grid):
    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == "#":
                count += 1
    return count

def printGrid(grid):
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            print(grid[i][j], end="")
        print()

def partOne(grid, numberOfIterations):
    returnThis = 0

    for _ in range(numberOfIterations):
        grid = partOneConversion(grid)
        returnThis += countOccupied(grid)
    return returnThis

def createPart3Grid(old, sizeOfOuterGrid):
    new = []
    centerGridX = len(old)
    centerGridY = len(old[0])

    gridStartX = (sizeOfOuterGrid - centerGridX) // 2
    gridStartY = (sizeOfOuterGrid - centerGridY) // 2

    for u in range(sizeOfOuterGrid):
        newLine = []
    
        for v in range(sizeOfOuterGrid):
            newLine.append(".")

            '''
            if u >= gridStartX and u < gridStartX + centerGridX:
                if v >= gridStartY and v < gridStartY + centerGridY:
                    newLine.append(old[u - gridStartX][v - gridStartY])
                else:
                    newLine.append(".")
            else:
                newLine.append(".")
            '''
        new.append(newLine) 
    return new


# Part One
example1 = read_file_to_2d_char_array("example1.txt")
printGrid(example1)
print("Part One Example:", partOne(example1, 10))  # Adjust iterations as needed
part1 = read_file_to_2d_char_array("part1.txt")
print("Part One:", partOne(part1, 10))  # Adjust iterations as needed

# Part Two
part2 = read_file_to_2d_char_array("part2.txt")
print("Part Two:", partOne(part2, 2025))  # Adjust iterations as needed

# Part Three
part3 = read_file_to_2d_char_array("example3.txt")
part3 = createPart3Grid(part3, 34)
printGrid(part3)
for n in range(1000000000 ):
    part3 = partOneConversion(part3)
    if n == 1000000:
        print(n)
    #printGrid(part3)

