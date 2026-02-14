class PathTree {
    constructor(x = 0,y = 0 ,depth = 0, wall, destX = 0, destY = 0) {
        this.x = x;
        this.y = y;
        this.depth = depth
        this.wall = wall;
        this.destX =destX;
        this.destY = destY;
        this.down = null;
        this.across = null;
    }

    plotpath(destX,dest, wall) {
        this.destX = destX;
        this.destY = destY;
    }

}

function renderWallPath(dataInput) {
    let wall = [];
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
    let x = 0;
    let y = 0;

    parseLetterNumbers(dataInput).forEach(([turn, paces]) => {
        console.log(`Turn: ${turn}, Paces: ${paces}`);
        direction = newDirection(turn,direction);
        for (let i = 0; i < paces; i++) {
            if (direction == 'N') y++;
            if (direction == 'E') x++;
            if (direction == 'S') y--;
            if (direction == 'W') x--;
            wall.push([x, y]);
        }
    });
    return wall
}

function getRevisedInfoWithBounds(trailData) {
    let StartX = 0; let StartY = 0;
    let lowX = 0; let lowY = 0;
    trailData.forEach(coordinate => {
        if (coordinate[0] <lowX)  lowX = coordinate[0];
        if (coordinate[1] < lowY) lowY = coordinate[1];
    });
    let xBound = 0; let yBound = 0;
    for (let i = 0; i < trailData.length; i++) {
        trailData[i][0] = trailData[i][0] - lowX;
        if (trailData[i][0] > xBound) xBound = trailData[i][0];
        trailData[i][1] = trailData[i][1] - lowY;
        if (trailData[i][1] > yBound) yBound = trailData[i][1]; 
    }
    startX = -lowX;
    startY = -lowY;
    return {trailData, startX, startY, xBound, yBound}
}

function exists(trailData,e,f) {
    trailData.forEach(coordinate => {
        if (coordinate[0] == e && coordinate[1] == f) {
            return true;
        }       
    });
    return false;   
}


/* MAIN FUNCTION */

let example1 = new renderWallPath("R3,R4,L3,L4,R3,R6,R9");

example1.forEach(coordinate => {
    console.log(`Coordinate: (${coordinate[0]}, ${coordinate[1]})`);
});
example1 = getRevisedInfoWithBounds(example1);
console.log(`StartX: ${example1.startX}, StartY: ${example1.startY}, xBound: ${example1.xBound}, yBound: ${example1.yBound}`);
example1.trailData.forEach(coordinate => {
    console.log(`Revised Coordinate: (${coordinate[0]}, ${coordinate[1]})`);
});

// make grid representation
for (let e = 0; e < example1.xBound + 1; e++) {
    let row = "";
    for (let f = 0; f < example1.yBound + 1; f++) {
        if (exists(example1.trailData,e,f)) {
            row += "#";
        } else {
            row += ".";
        }
    }
    console.log(row);
}




let Part1 = new renderWallPath("L6,L6,L6,R6,L6,L3,L3,R6,R6,L3,L3,R3,L6,R6,L6,L6,R3,L6,R6,L3,L6,R6,L6,R6,L6,L3,R6,L3,R3,L3,R3,L6,R6,L3,L3,R6,L3,R6,L3,L3,R3,R6,L6,R6,L3,L6,R6,R6,L3,L6,R3,L6,L3,R3,R6,L6,R3,L3,R3,L3");
