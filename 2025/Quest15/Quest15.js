class Map {
    
    constructor(parseData) {

        this.grid = [];
        this.wall = [];
        this.x = 0;
        this.y = 0;
        this.startX = 0;
        this.startY = 0;
        this.endx = 0;
        this.endy = 0;   
         
        function renderWallPath(dataInput) {
            // Function to parse the input string into an array of [letter, number] pairs
            function parseLetterNumbers(input) {
                let o = input
                .split(",")
                .map(s => s.trim())
                .map(item => [item[0], parseInt(item.slice(1), 10)]);
                return o;
            }

            // Function to determine the new direction based on the current direction and the turn
            function newDirection(turn,direction) {
                switch (turn) {
                    case "L": {
                        if (direction == 'N') return 'W';
                        if (direction == 'E') return 'N';
                        if (direction == 'S') return 'E';
                        if (direction == 'W') return 'S';
                    }
                    case "R": {
                        if (direction == 'N') return 'E';
                        if (direction == 'E') return 'S';
                        if (direction == 'S') return 'W';
                        if (direction == 'W') return 'N';
                    }
                }
            }
            let direction = 'N';
            // Establis the wall coordinates by parsing the input and following the turns and paces

            parseLetterNumbers(dataInput).forEach(([turn, paces]) => {
                console.log(`Turn: ${turn}, Paces: ${paces}`);
                direction = newDirection(turn,direction);
                for (let i = 0; i < paces; i++) {
                    if (direction == 'N') this.y++;
                    if (direction == 'E') this.x++;
                    if (direction == 'S') this.y--;
                    if (direction == 'W') this.x--;
                    this.wall.push([this.x, this.y]);
                }
            });
            this.endx = this.x;
            this.endy = this.y;
            // Establish the grid dimensions based on the wall coordinates
            let xLeft = 0;
            let xRight = 0;
            let yTop = 0;
            let yBottom = 0;
            for (let i = 0; i < this.wall.length; i++) {
                if (this.wall[i][0] < xLeft) xLeft = this.wall[i][0];
                if (this.wall[i][0] > xRight) xRight = this.wall[i][0];
                if (this.wall[i][1] > yBottom) yBottom = this.wall[i][1];
                if (this.wall[i][1] < yTop) yTop = this.wall[i][1];
            }
           // establish the new offsets and lengths for the grid based on the wall coordinates
           this.xOffset = -xLeft;
           this.yOffset = -yTop;
           this.endx +=this.xOffset;
           this.endy +=this.yOffset;
           yBottom += this.yOffset;
           xRight += this.xOffset;
           this.xLength = xRight - xLeft + 1;
           this.yLength = yBottom - yTop + 1;
           console.log(`xOffset: ${this.xOffset}, yOffset: ${this.yOffset}, xLength: ${this.xLength}, yLength: ${this.yLength}`);
           for (let i = 0; i < this.wall.length; i++) {
                this.wall[i][0] += this.xOffset;
                this.wall[i][1] += this.yOffset;
            }
            this.startX = this.xOffset;
            this.startY = this.yOffset;
            this.endx += this.xOffset;
            this.endy += this.yOffset;
            // create the grid. all points with the wall are marked with -1, the rest are marked with 0
            for (let i = 0; i < this.yLength; i++) {    
                this.newGridLine = [];
                for (let j = 0; j < this.xLength; j++) {
                    if (this.wall.some(w => w[0] == j && w[1] == i)) {
                        this.newGridLine.push(-1);
                    } else {
                        this.newGridLine.push(this.xLength * this.yLength); // a large number representing unvisited
                    }
                }
                this.grid.push(this.newGridLine);
            }
            this.grid[this.startY][this.startX] = (this.xLength*this.xLength); 
            this.grid[this.endy][this.endx] = (this.xLength*this.xLength); 
        }
        renderWallPath.call(this, parseData);
    }

    setPacesFromStart(xx = 0, yy = 0, pace = 0) {
        //console.log(`Setting pace at (${xx}, ${yy}) to ${pace}`);
        this.grid[xx][yy] = pace;
        
        // populate the grid with paces from the start point
        if (xx > 0) {
            //console.log(this.grid[xx-1][yy], " ", pace);
            if (this.grid[xx-1][yy] >= pace+1) {
                this.setPacesFromStart(xx-1,yy,pace+1);
            }
        }
        if (yy < this.yLength) {
            if( this.grid[xx][yy+1] >= pace+1) {
                this.setPacesFromStart(xx,yy+1,pace+1);
            }
        }
        if (yy > 0 && this.grid[xx][yy-1] >= pace+1) {
            this.setPacesFromStart(xx,yy-1,pace+1);
        }
        if (xx < this.xLength  && this.grid[xx+1][yy] >= pace+1) {
            this.setPacesFromStart(xx+1,yy,pace+1);
        }
        
    }

    printMap() {
        for (let i = 0; i < this.grid.length; i++) {
            let line = "";
            for (let j = 0; j < this.grid[i].length; j++) {
                line += this.grid[i][j].toString().padStart(4, ' ');

                  
            }
                //line += this.grid[i][j] + " ";
            console.log(line);
        }   
    }

};

/* MAIN FUNCTION */

let example1 = new Map("R3,R4,L3,L4,R3,R6,R9");
console.log(example1.wall);
console.log(`Start: (${example1.startX}, ${example1.startY})`);
console.log(`End: (${example1.endx}, ${example1.endy})`);

example1.setPacesFromStart();
example1.printMap();
console.log(`Paces from start to end: ${example1.grid[example1.endy][example1.endx]}`);
console.log(example1.endx, " " , example1.endy)
