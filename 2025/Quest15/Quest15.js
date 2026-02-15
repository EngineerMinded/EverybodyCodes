/*
    Wayne Mack
    Everybody Codes
    Quest 15
*/

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
    let destX = trailData[trailData.length - 1][0];
    let destY = trailData[trailData.length - 1][1];
    return {trailData, startX, startY, xBound, yBound, destX, destY};
}

function exists(trailData,e,f) {
    for (let o = 0; o < trailData.length; o++) {
        if (trailData[o][0] == e && trailData[o][1] == f) return true;    
    }
    return false;   
}

function makeGrid(trailData, xBound, yBound) {
    let grid = [];
    for (let i = 0; i <= yBound; i++) {
        let row = [];
        for (let j = 0; j <= xBound; j++) {
            if (exists(trailData,j,i)) row.push(-1);
            else row.push(xBound * yBound);
        }
        grid.push(row);
    }
    let destX =0;
    let destY =0;
    [destX,destY] = trailData[trailData.length - 1];
    console.log(destX, destY);
    grid[destY][destX] = xBound * yBound;
    return grid;
}

function printList(list) {
    list.forEach(item => {
        console.log(item);
    }); 
}

function printGrid(grid) {
    grid.forEach(row => { 
        let line = [];
        row.forEach(cell => {
            if (cell == -1) line.push("X");
            else line.push(" ");
        });
        console.log(line.join(" "));
    }
    );
}

function findShortestPath(grid, startX = 0, startY = 0, destX = 0, destY = 0) { 
    let queue = [[startX, startY, 0]];
    let directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    while (queue.length > 0) {
        let [x, y, dist] = queue.shift();
        if (x == destX && y == destY) return dist;  
        for (let [dx, dy] of directions) {
            let newX = x + dx;
            let newY = y + dy;
            if (newX >= 0 && newX < grid[0].length && newY >= 0 && newY < grid.length && grid[newY][newX] > dist + 1) {
                grid[newY][newX] = dist + 1;
                queue.push([newX, newY, dist + 1]);
            }
        }
    }
    return -1; 
}

function partOne(dataInput) {
    let wall = renderWallPath(dataInput);
    let revisedInfo = getRevisedInfoWithBounds(wall);
    let grid = makeGrid(revisedInfo.trailData, revisedInfo.xBound, revisedInfo.yBound);
    return findShortestPath(grid, revisedInfo.startX, revisedInfo.startY, revisedInfo.destX, revisedInfo.destY);
}

function parseLargeWallDimensions(dataInput) {

    function splitLetterNumber(str) {
        const letter = str.match(/[A-Za-z]+/)[0];
        const number = parseInt(str.match(/\d+/)[0], 10);
        return { letter, number };
    }

    function getWallComponents(lineInput, direction = 'X') {
        _newDirection , paces = splitLetterNumber(lineInput);
        if (currentDirection == 'X') {
            if (_newDirection == 'L') direction = 'W';
            else direction = 'E';
        }
        else {
            direction = newDirection(_newDirection, direction); 
        }
        return { direction, paces };
    }

    let x = 0, y = 0;
    let data = dataInput.split(",").map(s => s.trim());
    data.forEach(line => {
        console.log(line);
    });







}




/* MAIN FUNCTION */
// PART ONE
console.log("Example 1a: ", partOne("R3,R4,L3,L4,R3,R6,R9"));
console.log("Example 1b: ", partOne("L6,L3,L6,R3,L6,L3,L3,R6,L6,R6,L6,L6,R3,L3,L3,R3,R3,L6,L6,L3"));
console.log("Part 1: ", partOne("L6,L6,L6,R6,L6,L3,L3,R6,R6,L3,L3,R3,L6,R6,L6,L6,R3,L6,R6,L3,L6,R6,L6,R6,L6,L3,R6,L3,R3,L3,R3,L6,R6,L3,L3,R6,L3,R6,L3,L3,R3,R6,L6,R6,L3,L6,R6,R6,L3,L6,R3,L6,L3,R3,R6,L6,R3,L3,R3,L3"));
// PART TWO
console.log("Part 2: ", partOne("L55,L55,L77,L55,R77,L77,L33,L22,R11,L22,R22,R44,L66,R77,L22,L66,R44,L33,L66,L11,R11,R44,R77,L66,L22,R66,L88,R99,L22,L22,R99,L77,L33,R11,L33,L55,R22,R88,R66,L33,R77,L99,L11,R77,L66,L44,R88,R88,L22,R88,L99,L33,R55,L99,L44,R44,R44,L55,L11,R88,R99,L55,L88,R11,L33,R88,L77,L33,R22,R99,L66,R99,L44,L88,R77,L88,R77,L66,L22,L11,R22,R77,R11,L66,R44,L66,L55,R11,R44,L99,L88,R77,L88,R11,R99,L22,L11,R55,L77,L66,R44,R44,L66,L11,R44,L22,R11,R77,L22,L77,R44,L33,R66,L44,R88,L88,L55,L55,R55,R99,L11,R11,R44,L11,L66,R11,R66,L77,R44,L77,L11,R44,L33,R88,L66,L44,R11,R44,L55,R33,L44,R55,L88,R88,L99,L66,R66,L11,R99,L99,L77,R33,R66,L55,L22,R55,R77,L11,L55,R99,R44,L99,R99,L88,L44,L55,R88,R88,L44,R66,L55,R66,L11,R33,L88,R88,L77,L99,L11,R22,R44,R33,L88,R77,L22,L66,R66,L33,R99,L11"));
// PART THREE - YOU HAVE TO DO BETTER THAN THIS!
console.log("Part 3: ", parseLargeWallDimensions("R9093539,R5695611,R1598768,R1399594,L8397564,R9396334,R1299493,R2299333,L2299793,R1999780,L7699307,R5999460,L4599586,R2899739,R1898651,R2198438,L6299307,L4898579,R7099361,L9699127,R3699667,R2399304,R2999730,L5299523,L7294817,R6098231,L9592608,R7996880,R2799692,L8899199,R4098811,R2199758,L7297883,R7894391,R4199622,L2499725,L6499285,L1899791,L1598768,R7399334,R899919,L3099721,R2498075,L8294107,R7899289,R8293609,L6097621,R2398296,R2399784,L6199318,L5695611,R499615,L8696607,R2199802,R8094249,L9499145,R899649,L9696217,R4798128,R9296373,L7696997,L199858,R4696663,L9398966,R1199652,L5398434,R1299623,R1199652,L2598986,R7294379,L9592608,R299883,L8096841,R7494675,R7099361,R5098011,L5296237,L5298463,L9797158,R4498695,L4399516,R2398296,R3097613,L7694071,L9798922,R3897231,R1899791,L9392762,R7893917,R3898869,L6499415,L7599316,R699937,R4499505,L5798318,L7999280,R8094249,L9192916,R4598206,R3499615,L4596734,R3199712,R4599586,L2999730,R4098401,L6497465,L5699487,L7097941,R2699757,R6099451,L399964,R6198202,L9398966,R699937,L9697187,R1498935,R9493255,L599574,L7394746,R3498985,L4698167,R3299703,L8499235,R9696217,R7997680,R4696381,L7494675,L6195226,R1599376,L3399014,L5098521,R4696663,R9497245,L5598376,R1398922,L9899109,R7699153,R2199758,R2999670,L1799802,R1999820,L5598376,L4799568,L6599406,R9799118,R699503,R4999550,L2698947,L1999820,L1698691,R3998440,L7694071,R7494225,R4199622,L5698347,R2698947,R7799298,R5299417,L199922,L4996450,R1999820,L5698347,L399956,L5197972,R6395456,R4496805,L5099439,L6498115,R3497305,R5798318,L3598956,R8499065,L9399154,R7197912,R2098383,L999610,R1598864,R2099181,L3497515,L9899109,L9699127,R3797074,R2398296,L6299433,L7694071,R2698947,R4499505,L8094249,R9899109,R199982,L3499615,L6298173,R9897129,R6799252,L199858,L6097621,R1599536,L8897419,R999710,R199942,L7699307,R699461,L2098383,L8596646,R2599246,R7294817,L3099101,R4499595,L8297593,R8493965,R2499275,L1399454,R1199868,L1399874,L2598986,R499645,R799384,L4696381,L4199538,R299967,R699797,L799928,L6399424,L3698927,R6198202,L8193686,R699727,R1199532,L2797844,R6894687,L2399064,R4699577,R599934,L2399784,L4796304,R1298999,L9796178,R7097231,R6199318,L3797074"));