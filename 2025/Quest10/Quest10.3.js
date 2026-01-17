
const fs = require("fs");

function readFileTo2DCharArray(filename) {
    const text = fs.readFileSync(filename, "utf8");

    // Split into lines, then split each line into characters
    const grid = text
        .split(/\r?\n/)        // handle Windows + Unix line endings
        .map(line => line.split(""));  // convert each line into an array of chars
        grid.forEach(row => row.pop()); // remove last empty element caused by trailing newline
        dx = grid.length;
        dy = grid[0].length;
        for (let i = 0; i < grid.length; i++) {
            for (let j = 0; j < grid[i].length; j++) {
                switch (grid[i][j]) {
                    case 'D':{
                        startX = i;
                        startY = j;
                        break;      
                    }
                    case 'S':{
                        this.sheep.push([i,j]);
                        break;      
                    }   
                    case 'X':{
                        this.dragon.push([i,j]);
                        break;      
                    }   
                }
            }
        }
}

function exists(array,findX,findY) {
    array.forEach(element => {
        if (element[0] == findX && element[1] == findY) {
            return true;
        }   
    });
    return false;
}
function removePoint(array,findX,findY) {
    for (let i = 0; i < array.length; i++) {
        if (array[i][0] == findX && array[i][1] == findY) {
            array.splice(i,1);
            return;
        }       
    }
}   

class Grid {
    constructor() {
        startX = 0;
        startY = 0;
        this.dragon = [];
        this.sheep = [];
        this.grid = [];
        this.dx = 0;
        this.dy = 0;
    }
    readFromFile(filename) {
        this.grid = readFileTo2DCharArray(filename);
    }
    createBlank(lengthX,LengthY,starX,starY) {
        this.dx = lengthX;
        this.dy = LengthY;
        this.startX = starX;
        this.startY = starY;
        
    } 

    plotDragon(x,y, movesRemaining, partNumber) {
        if (!(exists(this.dragon,x,y)) && (movesRemaining == 0  || partNumber == 1)) {
            this.dragon.push([x,y]);
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
            if (x < this.dx - 2 && y >= 1 ) {
                this.plotpoint(x + 2, y - 1, movesRemaining - 1, partNumber);
            }
            if (x < this.dx - 1 && y >= 2 ) {  
                this.plotpoint(x + 1, y - 2, movesRemaining - 1, partNumber);
            }
            if (x >= 1 && y < this.dy - 2 ) {
                this.plotpoint(x - 1, y + 2, movesRemaining - 1, partNumber);
            }   
            if (x >= 2 && y <= dy -1) {
                this.plotpoint(x - 2, y + 1, movesRemaining - 1, partNumber);
            }
            if (x < this.dx - 2 && y < this.grid[0].length - 1 ) {
                this.plotpoint(x + 2, y + 1, movesRemaining - 1, partNumber);
            }   
            if (x < this.grid.length - 1 && y < this.grid[0].length - 2 ) {
                this.plotpoint(x + 1, y + 2, movesRemaining - 1, partNumber);
            }
            
        }
    }
    
    startPlotting(movesRemaining, partNumber) {
        this.plotpoint(this.startX, this.startY, movesRemaining, partNumber);
    }

    countAllSheep() {
        return this.sheep.length;
    }

    printGrid() {
        for (let i = 0; i < dx; i++) {
            line = "";
            for (let j = 0; j <dy; j++) {
                if (exists(this.dragon,i,j)) {
                    line += 'X';
                }
                else if (exists(this.sheep,i,j)){
                    line += 'S';
                }
                else {
                    line += '.';
                }
            }
            console.log(line);
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
   // This way is not efficent and it may because of the plotpoint for large data. make it more efficent
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
        let dragonGrid = new Grid();
        for (let phase = 0; phase < numberOfPhases; phase++) {
            console.log(`--- Phase ${phase + 1} ---`);
            dragonGrid = new Grid();
            dragonGrid.createBlank(this.grid.length,this.grid[0].length,dX,dY); 
            dragonGrid.startPlotting(phase + 1,2);
            
            dragonGrid.printGrid();
            //this.printGrid();
            for (let k = 0; k < 2; k++) {
                for (let i = 0; i < this.grid.length; i++) {
                    for (let j = 0; j < this.grid[i].length; j++) {
                        if (dragonGrid.grid[i][j] == 'X') {
                            //console.log(`Dragon can reach (${i}, ${j})`);
                            if (this.grid[i][j] == 'S') {
                                //console.log(`Sheep at (${i}, ${j}) was eaten by the dragon.`);
                                this.grid[i][j] = '.';
                                sheepThatWereEaten++;
                            }
                        }
                    }
                }
                if (k == 0) {this.moveSheep();}
            }
            console.log(`After phase ${phase + 1}, sheep eaten so far: ${sheepThatWereEaten}`);
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

let example0 = new Grid();
example0.readFromFile("example0.txt");
example0.startPlotting(3,2);
example0.printGrid();
/*
let example2 = new Grid();
example2.readFromFile("example2.txt");
example2.printGrid
console.log ('Sheep that were eaten: ' , example2.part2Sequence(3));

let puzzle2 = new Grid();
puzzle2.readFromFile("puzzle2.txt");
console.log ('Sheep that were eaten: ' , puzzle2.part2Sequence(20));
*/