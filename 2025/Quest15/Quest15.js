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


/* MAIN FUNCTION */

let example1 = new Map("R3,R4,L3,L4,R3,R6,R9");


let Part1 = new Map("L6,L6,L6,R6,L6,L3,L3,R6,R6,L3,L3,R3,L6,R6,L6,L6,R3,L6,R6,L3,L6,R6,L6,R6,L6,L3,R6,L3,R3,L3,R3,L6,R6,L3,L3,R6,L3,R6,L3,L3,R3,R6,L6,R6,L3,L6,R6,R6,L3,L6,R3,L6,L3,R3,R6,L6,R3,L3,R3,L3");
