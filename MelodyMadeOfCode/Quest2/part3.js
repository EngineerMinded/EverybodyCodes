// Wayne Mack
// Everybody Codes
// Quest 2

const fs = require('fs');

function read2DCharArray(path) {
  const lines = fs.readFileSync(path, 'utf8').split(/\r?\n/);
  return lines.map(line => [...line]);
}

class Grid {
   grid = []
   yourPosition = [];
   destinationPosition = [];
   direction = 'north';
   read2DCharArray(path) {
        const lines = fs.readFileSync(path, 'utf8').split(/\r?\n/);
        return lines.map(line => [line]);
    }
    constructor(filename) {
        this.direction = 'north';
        this.grid = read2DCharArray(filename);
        this.grid.forEach((row, rowIndex) => {
            row.forEach((cell, colIndex) => {
                //console.log(cell);
                if (cell === '@') {
                    this.yourPosition = [rowIndex, colIndex];
                }
                if (cell === '#') {
                    this.destinationPosition = [rowIndex, colIndex];
                }
            });
        });
    }
    changeDirection() {
        if (this.direction === 'north') {
            this.direction = 'east';
        } else if (this.direction === 'east') {
            this.direction = 'south';
        } else if (this.direction === 'south') {
            this.direction = 'west';
        } else if (this.direction === 'west') {
            this.direction = 'north';   
        }   
    }
    expandGrid() {
        const newGrid = [];
        for (let i = 0; i < this.grid.length + 2; i++) {
            const newRow = [];
            for (let j = 0; j < this.grid[0].length + 2; j++) {
                if (i === 0 || i === this.grid.length + 1 || j === 0 || j === this.grid[0].length + 1) {
                    newRow.push('.');
                } else {
                    newRow.push(this.grid[i - 1][j - 1]);
                }
            }
            newGrid.push(newRow);
        }   
        this.grid = newGrid;
        this.yourPosition[0] += 1;
        this.yourPosition[1] += 1;
        this.destinationPosition[0] += 1;
        this.destinationPosition[1] += 1;   
    }



    printGrid() {
        this.grid.forEach(row => {
            console.log(row.join(''));
        });
    }

    destinationIsSurrounded() {
        return (this.grid[this.destinationPosition[0] - 1][this.destinationPosition[1]] !== '.' &&
                this.grid[this.destinationPosition[0] + 1][this.destinationPosition[1]] !== '.' &&
                this.grid[this.destinationPosition[0]][this.destinationPosition[1] - 1] !== '.' &&
                this.grid[this.destinationPosition[0]][this.destinationPosition[1] + 1] !== '.');
    }

    checkpropogationonAllSides() {
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[0].length; j++) {
                if (this.grid[i][j] === '.') {
                    // Check all four sides
                    if (i > 0 && this.grid[i - 1][j] !== '.') {
                        if (i < this.grid.length - 1 && this.grid[i + 1][j] !== '.') {
                            if (j > 0 && this.grid[i][j - 1] !== '.') {
                                if (j < this.grid[0].length - 1 && this.grid[i][j + 1] !== '.') {
                                    this.grid[i][j] = '+';
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    partThreeMove() {
        let steps = 0; let directionCount = 0
        while (!this.destinationIsSurrounded()) {
            console.log(this.yourPosition, " ", this.destinationPosition," ",steps);
            this.grid[this.yourPosition[0]][this.yourPosition[1]] = '+';
            if (this.direction === 'north') {
                if (this.yourPosition[0] > 0 &&
                    this.grid[this.yourPosition[0] - 1][this.yourPosition[1]] === '.') {
                    this.yourPosition[0] -= 1;
                    this.grid[this.yourPosition[0]][this.yourPosition[1]] = '@';
                    steps+=1;
                     this.printGrid();
                }
            } else if (this.direction === 'east') {
                if (this.yourPosition[1] < this.grid[0].length - 1 &&
                    this.grid[this.yourPosition[0]][this.yourPosition[1] + 1] === '.' ) {
                    this.yourPosition[1] += 1;
                    this.grid[this.yourPosition[0]][this.yourPosition[1]] = '@';
                    steps+=1;
                     this.printGrid();
                } 
            } else if (this.direction === 'south') {
                if (this.yourPosition[0] < this.grid.length - 1 &&
                    this.grid[this.yourPosition[0] + 1][this.yourPosition[1]] === '.' ) {
                    this.yourPosition[0] += 1;
                    this.grid[this.yourPosition[0]][this.yourPosition[1]] = '@';
                    steps+=1;
                     this.printGrid();
                }
            } else if (this.direction === 'west') {
                if (this.yourPosition[1] > 0 &&
                    this.grid[this.yourPosition[0]][this.yourPosition[1] - 1] === '.') {
                    this.yourPosition[1] -= 1;
                    this.grid[this.yourPosition[0]][this.yourPosition[1]] = '@';
                    steps+=1;
                     this.printGrid();
                }
            }
            // expand the grid if we are about to go out of bounds
            if (this.yourPosition[0] === 0 || this.yourPosition[0] === this.grid.length - 1 ||
                this.yourPosition[1] === 0 || this.yourPosition[1] === this.grid[0].length - 1) {
                this.expandGrid();
            }
            this.checkpropogationonAllSides();
            directionCount++;
            if (directionCount > 2) {
                this.changeDirection();
                directionCount = 0;
            }
        }
        this.printGrid();
        return steps;
    }
};

// Example:
const example1 = new Grid('example3.txt');
console.log(example1.partThreeMove()); // 10  
