
const fs = require("fs");

function readFileTo2DCharArray(filename) {
    const text = fs.readFileSync(filename, "utf8");

    // Split into lines, then split each line into characters
    const grid = text
        .split(/\r?\n/)        // handle Windows + Unix line endings
        .map(line => line.split(""));  // convert each line into an array of chars

    return grid;
}

class dragonPoints {

    constructor(x,y) {
        this.points = [];
        this.xRange = x;
        this.yRange = y;
    }

    addPoint(x, y) {
        this.points.push([x,y]);
    }

    exists(x,y){
        for (let point of this.points) {
            if (point[0] == x && point[1] == y) {
                return true;
            }       
        }
        return false;   
    }

    knightMoves(deleteLastGeneration) {
        let newPoints = [];
        this.points.forEach(point => {
            let [x, y] = point;
            // Generate all 8 possible knight moves
            if (x >= 1 && y >= 2  && !this.exists(x - 1, y - 2)) {
                newPoints.push([x - 1, y - 2]);
            }
            if (x >= 2 && y >= 1  && !this.exists(x - 2, y - 1)) {
                newPoints.push([x - 2, y - 1]);
            }   
            if (x < this.xRange - 2 && y >= 1  && !this.exists(x + 2, y - 1)) {
                newPoints.push([x + 2, y - 1]);
            }
            if (x < this.xRange - 1 && y >= 2 && !this.exists(x + 1, y - 2)) {
                newPoints.push([x + 1, y - 2]);
            }   
            if (x >= 1 && y < this.yRange - 2 && !this.exists(x - 1, y + 2)) {
                newPoints.push([x - 1, y + 2]);
            }
            if (x >= 2 && y <= this.yRange -1 && !this.exists(x - 2, y + 1)) {
                newPoints.push([x - 2, y + 1]);
            }
            if (x < this.xRange - 2 && y < this.yRange - 1  && !this.exists(x + 2, y + 1)) {
                newPoints.push([x + 2, y + 1]);
            }   
            if (x < this.xRange - 1 && y < this.yRange - 2 && !this.exists(x + 1, y + 2)) {
                newPoints.push([x + 1, y + 2]);
            }
        });
        if (deleteLastGeneration) {
            this.points = [];
        
        }
        newPoints.forEach(point => {
            if (!this.exists(point[0], point[1])) {
                this.points.push(point);
            }
        });     

    }

}

class Grid {
    constructor() {
        this.grid = [];
        this.dx = 0;
        this.dy = 0;
        this.dragonMoves = [];
        this.sheepPositions = [];
    }
    readFromFile(filename) {
        this.grid = readFileTo2DCharArray(filename);
    }
    createBlank(lengthX,LengthY,starX,starY) {
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
    moveSheep() {
        for (let i = this.grid.length - 1; i > 0; i--) {
            for (let j = 0; j < this.grid[i].length; j++) {
                    if (this.grid[i -1][j] == 'S') {
                        if (this.grid[i][j] == '#') {
                            this.grid[i][j] = 's';
                        }
                        else if (this.grid[i][j] = '.') {
                            this.grid[i][j] = 'S';
                        }
                        this.grid[i - 1][j] = '.';
                    }
                    else if (this.grid[i - 1][j] == 's') {
                        if (this.grid[i][j] == '#') {
                            this.grid[i][j] = 's';
                        }
                        else if (this.grid[i][j] = '.') {
                            this.grid[i][j] = 'S';
                        }
                        this.grid[i - 1][j] = '#'
                    }
                    else if (this.grid[i - 1][j] == '.') {
                        if (this.grid[i][j] != '#') {
                            this.grid[i][j] = '.';
                        }
                    }

            }
        }
    }

    part2Sequence(numberOfPhases) {
        let sheepThatWereEaten = 0;
        let dX = 0; let dY = 0;
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'D') {
                    dX = i; dY = j; break;
                }
            }
        }
        let dragonGrid = new dragonPoints(this.grid.length, this.grid[0].length);
        dragonGrid.addPoint(dX, dY);
        for (let phase = 0; phase < numberOfPhases; phase++) {
            dragonGrid.knightMoves(true);
            
            for (let k = 0; k < 2; k++) {
                dragonGrid.points.forEach(point => {
                    let [x, y] = point;
                    // Mark dragon reachable positions on the grid
                    if (this.grid[x][y] == 'S') {
                        this.grid[x][y] = '.';
                        sheepThatWereEaten++;
                    }
                });
                if (k == 0) {this.moveSheep();} 
            }
        }
        return sheepThatWereEaten;
    }
}

let example1 = new Grid();
example1.readFromFile("example1.txt")
example1.startPlotting(3,1);
console.log(`Sheep reached in example1: ${example1.countAllSheep()}`);

let puzzle1 = new Grid();
puzzle1.readFromFile("puzzle1.txt")
puzzle1.startPlotting(4,1);
console.log(`Sheep reached in puzzle1: ${puzzle1.countAllSheep()}`);

let example2 = new Grid();
example2.readFromFile("example2.txt");
example2.printGrid
console.log ('Sheep that were eaten: ' , example2.part2Sequence(3));

let puzzle2 = new Grid();
puzzle2.readFromFile("puzzle2.txt");
console.log ('Sheep that were eaten: ' , puzzle2.part2Sequence(20));