'''
    Wayne Mack
    Everybody Codes
    Quest 14
'''
# --- Read File Contents and make 2D Character Array ---
def read_file_to_2d_char_array(filename):
    grid = []
    with open(filename, "r", encoding="utf-8") as f:
        for line in f:
            # Keep the characters, strip the newline
            row = list(line.rstrip("\n"))
            grid.append(row)
    return grid

# --- Generate next generations of Grid Per the Rules ---   
def generationConversion(old):
    new = []
    # -- Convert a single character based on diagonal neighbors ---
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

# --- Count Occupied spaces in Grid ---
def countOccupied(grid):
    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == "#":
                count += 1
    return count

# --- Print Grid to Console (for debugging) ---
def printGrid(grid):
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            print(grid[i][j], end="")
        print()

# --- Procedure for Part One and Two ---
def partOne(grid, numberOfIterations):
    returnThis = 0

    for _ in range(numberOfIterations):
        grid = generationConversion(grid)
        returnThis += countOccupied(grid)
    return returnThis

# --- Create a larger grid for Part Three: A blank template ---
def createPart3Grid( sizeOfOuterGrid):
    new = []
  

    for u in range(sizeOfOuterGrid):
        newLine = []
    
        for v in range(sizeOfOuterGrid):
            newLine.append(".")
        new.append(newLine) 
    return new

# --- Check if pattern exists at center of grid for Part 3's procedure ---
def gridHasPatternAtCenter(grid, pattern, centerX, centerY):
    patternSizeX = len(pattern)
    patternSizeY = len(pattern[0])

    startX = centerX - patternSizeX // 2
    startY = centerY - patternSizeY // 2

    for i in range(patternSizeX):
        for j in range(patternSizeY):
            if grid[startX + i][startY + j] != pattern[i][j]:
                return False
    return True

# --- Find repetitive patterns in Part Three ---
def find_repetitive_patterns(diffs, current_iteration):
    n = 0
    length = len(diffs)
    for i in range(1, length // 2 + 1):
        is_pattern = True
        for j in range(length - i):
            if diffs[j] != diffs[j + i]:
                is_pattern = False
                break
        if is_pattern:
            n = i
            break
    
    return (n, diffs,current_iteration)

# --- Procedure for Part Three ---
def partThree(grid, pattern, iterations):
    firstOccurence = 0
    patternToFind = []
    numberPlaces = []
    for m in range(iterations):
        grid = generationConversion(grid)
        if gridHasPatternAtCenter(grid, pattern, 17, 17):
            if firstOccurence == 0:
                firstOccurence = m + 1
            patternToFind.append(countOccupied(grid))
            numberPlaces.append((m + 1))    
            (u,v,w) = find_repetitive_patterns(patternToFind,numberPlaces)
            if u > 0:
                jumps = []
                for i in range(u):
                    jumps.append(w[i + 1] - w[i])
                count = firstOccurence
                answer = 0
                while count + u < iterations:
                    for t in range(u):
                        count += jumps[t]
                        answer += v[t]
                        if count >= iterations:
                            break
                return answer

'''MAIN PROGRAM EXECUTION'''    
# Part One
example1 = read_file_to_2d_char_array("example1.txt")
print("Part One Example:", partOne(example1, 10))  # Adjust iterations as needed
part1 = read_file_to_2d_char_array("part1.txt")
print("Part One:", partOne(part1, 10))  # Adjust iterations as needed

# Part Two
part2 = read_file_to_2d_char_array("part2.txt")
print("Part Two:", partOne(part2, 2025))  # Adjust iterations as needed

# Part Three
example3Find = read_file_to_2d_char_array("example3.txt")
example3 = createPart3Grid( 34)
print ("Example 3: " ,partThree(example3, example3Find, 1000000000))  # Adjust iterations as needed

part3 = read_file_to_2d_char_array("part3.txt")
part3Grid = createPart3Grid( 34)
print ("Part 3: " , partThree(part3Grid, part3, 1000000000))
