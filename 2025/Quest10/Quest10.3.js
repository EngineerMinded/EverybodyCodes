
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

    addPoint(x, y) {this.points.push([x,y]);}

    exists(x,y){
        for (let point of this.points) {
            if (point[0] == x && point[1] == y) {return true;}       
        }
        return false;   
    }

    knightMoves(deleteLastGeneration) {
        let newPoints = [];
        this.points.forEach(point => {
            let [x, y] = point;
            // Generate all 8 possible knight moves
            if (x >= 1 && y >= 2  && !this.exists(x - 1, y - 2)) {newPoints.push([x - 1, y - 2]);}
            if (x >= 2 && y >= 1  && !this.exists(x - 2, y - 1)) {newPoints.push([x - 2, y - 1]);}   
            if (x < this.xRange - 2 && y >= 1  && !this.exists(x + 2, y - 1)) {newPoints.push([x + 2, y - 1]);}
            if (x < this.xRange - 1 && y >= 2 && !this.exists(x + 1, y - 2)) {newPoints.push([x + 1, y - 2]);}   
            if (x >= 1 && y < this.yRange - 2 && !this.exists(x - 1, y + 2)) {newPoints.push([x - 1, y + 2]);}
            if (x >= 2 && y <= this.yRange -1 && !this.exists(x - 2, y + 1)) {newPoints.push([x - 2, y + 1]);}
            if (x < this.xRange - 2 && y < this.yRange - 1  && !this.exists(x + 2, y + 1)) {newPoints.push([x + 2, y + 1]);}   
            if (x < this.xRange - 1 && y < this.yRange - 2 && !this.exists(x + 1, y + 2)) {newPoints.push([x + 1, y + 2]);}
        });
        if (deleteLastGeneration) {this.points = [];}
        newPoints.forEach(point => {
            if (!this.exists(point[0], point[1])) {this.points.push(point);}
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

    plotpoint(x,y, movesRemaining, partNumber) {
        //console.log(`Plotting point at (${x}, ${y}) with ${movesRemaining} moves remaining.`);
        if (this.grid[x][y] == '.' || this.grid[x][y] == 'S' || this.grid[x][y] == 'X' || this.grid[x][y] == 'Z') {
            this.grid[x][y] == 'S' || this.grid[x][y] == 'Z' ? this.grid[x][y] = 'Z' : this.grid[x][y] = 'X';
            if ( movesRemaining > 0 && partNumber == 2) {this.grid[x][y] == 'Z'? this.grid[x][y] = 'S' : this.grid[x][y] = '.';}
            if (movesRemaining == 0) {return;}
        // check all 8 possible next moves
            if (x >= 1 && y >= 2 ) {this.plotpoint(x - 1, y - 2, movesRemaining - 1, partNumber);}
            if (x >= 2 && y >= 1 ) {this.plotpoint(x - 2, y - 1, movesRemaining - 1, partNumber);}
            if (x < this.grid.length - 2 && y >= 1 ) {this.plotpoint(x + 2, y - 1, movesRemaining - 1, partNumber);}
            if (x < this.grid.length - 1 && y >= 2 ) {this.plotpoint(x + 1, y - 2, movesRemaining - 1, partNumber);}
            if (x >= 1 && y < this.grid[0].length - 2 ) {this.plotpoint(x - 1, y + 2, movesRemaining - 1, partNumber);}   
            if (x >= 2 && y <= this.grid[0].length -1) {this.plotpoint(x - 2, y + 1, movesRemaining - 1, partNumber);}
            if (x < this.grid.length - 2 && y < this.grid[0].length - 1 ) {this.plotpoint(x + 2, y + 1, movesRemaining - 1, partNumber);}   
            if (x < this.grid.length - 1 && y < this.grid[0].length - 2 ) {this.plotpoint(x + 1, y + 2, movesRemaining - 1, partNumber);}
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
                if (this.grid[i][j] == 'Z') {sheepCount++;}
            }
        }    return sheepCount;
    }

    printGrid() {
        for (let i = 0; i < this.grid.length; i++) {console.log(this.grid[i].join(''));}       
    }

    moveIndividualSheep(i, j) {
        console.log(`Moving sheep at (${i}, ${j})`);
        if (this.grid[i -1][j] == 'S') {
            if (this.grid[i][j] == '#') {this.grid[i][j] = 's';}
            else if (this.grid[i][j] = '.') {this.grid[i][j] = 'S';}
            this.grid[i - 1][j] = '.';
        }
        else if (this.grid[i - 1][j] == 's') {
            if (this.grid[i][j] == '#') {this.grid[i][j] = 's';}
            else if (this.grid[i][j] = '.') {this.grid[i][j] = 'S';}
            this.grid[i - 1][j] = '#'
        }
        else if (this.grid[i - 1][j] == '.') {
            if (this.grid[i][j] != '#') {this.grid[i][j] = '.';}
        }
    }
    moveSheep() {
        for (let i = this.grid.length - 1; i > 0; i--) {
            for (let j = 0; j < this.grid[i].length; j++) {
                this.moveIndividualSheep(i, j);
            }
        }
    }

    part2Sequence(numberOfPhases) {
        let sheepThatWereEaten = 0;
        let dX = 0; let dY = 0;
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'D') {dX = i; dY = j; break;}
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
    /********************************************
     * -1 = sheep remains in play               *
     *  0 = sheep reached bottom row and remain *
     *  1 = all sheep eaten                     *
     ********************************************/
    sheepStillRemains() {
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'S') {
                    return true;
                }
            }
        }
        return false;
    }

     moveSheepRow(row) {
        for (let i = this.grid.length - 1; i > 0; i--) {
            this.moveIndividualSheep(i, row);
        }
    }

    part3Moves(i, j, sheepMove) {
        if (this.grid[i][j] == 'S') {
            this.grid[i][j] = '.';
        }
        if (!(this.sheepStillRemains())) {
            return 1;
        }
        this.moveSheepRow(sheepMove);
        if (!(this.sheepStillRemains())) {
            return 0;
        }
        sheepMove += 1;
        if (sheepMove >= this.grid[0].length) {sheepMove = 0;}      

        let totalfinishes = 0;

        // Check all 8 possible knight moves
        for (let k = 0; k < sheepMove; k++) {
            if (k != sheepMove) {
                if (i >= 1 && j >= 2 ) {totalfinishes += this.part3Moves(i - 1, j - 2, k);}
                if (i >= 2 && j >= 1 ) {totalfinishes += this.part3Moves( i - 2, j - 1, k);}
                if (i < this.grid.length - 2 && j >= 1 ) {totalfinishes += this.part3Moves( i + 2, j - 1, k);} 
                if (i < this.grid.length - 1 && j >= 2 ) {totalfinishes += this.part3Moves( i + 1, j - 2, k);}
                if (i >= 1 && j < this.grid[0].length - 2 ) {totalfinishes += this.part3Moves( i - 1, j + 2, k);}
                if (i >= 2 && j <= this.grid[0].length -1 ) {totalfinishes += this.part3Moves( i - 2, j + 1, k);}
                if (i < this.grid.length - 2 && j < this.grid[0].length - 1) {totalfinishes += this.part3Moves( i + 2, j + 1, k);}
                if (i < this.grid.length - 1 && j < this.grid[0].length - 2) {totalfinishes += this.part3Moves( i + 1, j + 2, k);}
            }
        }
        return totalfinishes;
    }

    part3Move(startX, startY) {
        let total  = 0;
        for (let k = 0; k < this.grid[0].length; k++) {
            total += this.part3Moves(startX, startY, k);
        }
        return total;
    }

    findpartStartPoint () {
        for (let i = 0; i < this.grid.length; i++) {
            for (let j = 0; j < this.grid[i].length; j++) {
                if (this.grid[i][j] == 'D') {
                    this.grid[i][j] = ".";
                    return [i, j];
                }
            }
        }
    }
 
}

/*
let example1 = new Grid();
example1.readFromFile("example1.txt")
example1.startPlotting(3,1);
console.log('Sheep reached in example1:' ,example1.countAllSheep());

let puzzle1 = new Grid();
puzzle1.readFromFile("puzzle1.txt")
puzzle1.startPlotting(4,1);
console.log(`Sheep reached in puzzle1: `, puzzle1.countAllSheep());

let example2 = new Grid();
example2.readFromFile("example2.txt");
console.log ('Sheep that were eaten in Example 2: ' , example2.part2Sequence(3));

let puzzle2 = new Grid();
puzzle2.readFromFile("puzzle2.txt");
console.log ('Sheep that were eaten in Puzzle 2: ' , puzzle2.part2Sequence(20));
*/
let example3a = new Grid();
example3a.readFromFile("example3a.txt");
example3a.printGrid();
let [startX, startY] = example3a.findpartStartPoint();
console.log('Number of ways for Example 3a: ', example3a.part3Moves(startX,startY, 0));

let example3b = new Grid();
example3b.readFromFile("example3b.txt");
let [startXb, startYb] = example3b.findpartStartPoint();
console.log('Number of ways for Example 3b: ', example3b.part3Moves(startXb,startYb, 0));
let puzzle3 = new Grid();

