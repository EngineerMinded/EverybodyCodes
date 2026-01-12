
const fs = require("fs");

function readFileTo2DCharArray(filename) {
    const text = fs.readFileSync(filename, "utf8");

    // Split into lines, then split each line into characters
    const grid = text
        .split(/\r?\n/)        // handle Windows + Unix line endings
        .map(line => line.split(""));  // convert each line into an array of chars

    return grid;
}

class Grid {
    constructor(filename) {
        this.grid = readFileTo2DCharArray(filename);
    }
    constructor(lengthX,LengthY,starX,starY) {
        for (let i = 0; i < lengthX; i++) {
            let newline = [];   
            for (let j = 0; j < LengthY; j++) {
                if (i == starX && j == starY) {
                    newline.push('D');
                } else {
                    newline.push('.');
                }           
            }
            this.grid.push(newline);
        }
    } 

    plotpoint(x,y, movesRemaining, partNumber) {
        //console.log(`Plotting point at (${x}, ${y}) with ${movesRemaining} moves remaining.`);
        if (this.grid[x][y] == '.' || this.grid[x][y] == 'S' || this.grid[x][y] == 'X' || this.grid[x][y] == 'Z') {
            this.grid[x][y] == 'S' || this.grid[x][y] == 'Z' ? this.grid[x][y] = 'Z' : this.grid[x][y] = 'X';
            if ( movesRemaining > 0 && partNumber == 2) {
                 this.grid[x][y] == 'Z'? this.grid[x][y] = 'S' : this.grid[x][y] = '.';
            }
        
            if (movesRemaining == 0) {
                return;
            }
        // check all 8 possible next moves
            if (x >= 1 && y >= 2 ) {
                this.plotpoint(x - 1, y - 2, movesRemaining - 1, partNumber);
            }
            if (x >= 2 && y >= 1 ) {
                this.plotpoint(x - 2, y - 1, movesRemaining - 1, partNumber);
            }
            if (x < this.grid.length - 2 && y >= 1 ) {
                this.plotpoint(x + 2, y - 1, movesRemaining - 1, partNumber);
            }
            if (x < this.grid.length - 1 && y >= 2 ) {  
                this.plotpoint(x + 1, y - 2, movesRemaining - 1, partNumber);
            }
            if (x >= 1 && y < this.grid[0].length - 2 ) {
                this.plotpoint(x - 1, y + 2, movesRemaining - 1, partNumber);
            }   
            if (x >= 2 && y <= this.grid[0].length -1) {
                this.plotpoint(x - 2, y + 1, movesRemaining - 1, partNumber);
            }
            if (x < this.grid.length - 2 && y < this.grid[0].length - 1 ) {
                this.plotpoint(x + 2, y + 1, movesRemaining - 1, partNumber);
            }   
            if (x < this.grid.length - 1 && y < this.grid[0].length - 2 ) {
                this.plotpoint(x + 1, y + 2, movesRemaining - 1, partNumber);
            }
            
        }
    }
    
    startPlotting(movesRemaining, partNumber) {
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'D') {
                    this.grid[i][j] = ".";
                    this.plotpoint(i, j, movesRemaining, partNumber);
                }
            }
        }
    }

    countAllSheep() {
        let sheepCount = 0;
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'Z') {
                    sheepCount++;
                }
            }
        }    return sheepCount;
    }

    printGrid() {
        for (let i = 0; i < this.grid.length; i++) {
            console.log(this.grid[i].join(''));
        }       
    }
   // FINISH UP ON PART 2 SEQUENCE
    part2Sequence(numberOfPhases) {
        function moveSheep() {
            for (let i = 1; i < this.grid.length; i++) {
                for (let j = 0; j < this.grid[i].length; j++) {
                    if (i < this,grid.length - 1) {
                        if (this.grid[i -1][j] == 'S') {
                            if (this.grid[i][j] == '#') {
                                this.grid[i][j] = 's';
                            }
                            else if (this.grid[i -1][j] = '.')
                                this.grid[i -1][j] = 'S';
                        }
                        if (this.grid[i - 1][j] == 's') {
                            if (this.grid[i][j] == '#') {
                                this.grid[i][j] = 's';
                            }
                        }
                    }
                }
            }
        }

        let dX = 0; let dY = 0;
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'D') {
                    dX = i; dY = j; break;
                }
            }
        }
        let dragonGrid = new Grid(this.grid.length, this.grid[0].length,dX,dY); 
        for (let phase = 0; phase < numberOfPhases; phase++) {
            dragonGrid.startPlotting(1,2);

        }
    }
}

let example1 = new Grid("example1.txt")
example1.startPlotting(3,1);
console.log(`Sheep reached in example1: ${example1.countAllSheep()}`);

let puzzle1 = new Grid("puzzle1.txt")
puzzle1.startPlotting(4,1);
console.log(`Sheep reached in puzzle1: ${puzzle1.countAllSheep()}`);

let example0 = new Grid("example0.txt");
example0.startPlotting(3,2);
example0.printGrid();

let example2 = new Grid("example1.txt");
example2.startPlotting(3,2);