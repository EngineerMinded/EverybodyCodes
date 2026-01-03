// Wayne Mack
// Everybody Codes
// Quest 4

const fs = require('fs');

function readNumbersFromFile(filename) {
    // Read entire file as text
    const text = fs.readFileSync(filename, 'utf8');

    // Use regex to find all numbers (integers or decimals)
    const matches = text.match(/-?\d+(\.\d+)?/g);

    // Convert matches to actual numbers
    return matches ? matches.map(Number) : [];
}

function readNumberPairs(filename) {
    const text = fs.readFileSync(filename, 'utf8');

    const lines = text.split(/\r?\n/);

    const result = [];

    for (const line of lines) {
        const trimmed = line.trim();
        if (trimmed === "") continue; // skip empty lines

        // Split by '|'
        const parts = trimmed.split('|').map(s => s.trim());

        if (parts.length === 1) {
            // Only one number → duplicate it
            const num = Number(parts[0]);
            result.push([num, num]);
        } else if (parts.length === 2) {
            // Two numbers → use them as-is
            const num1 = Number(parts[0]);
            const num2 = Number(parts[1]);
            result.push([num1, num2]);
        } else {
            // More than two parts — optional: handle or ignore
            console.warn("Unexpected format:", line);
        }
    }

    return result;
}

function getdoubleGearRPM( speed, gears) {
    for (let i = 1;  i < gears.length; i++) {
        var gear1B = gears[i - 1][1];
        var gear2A = gears[i ][0];  
        var ratio2  = gear1B / gear2A;
        speed = speed * ratio2;
    }
    return speed;
}

function getGearRPM( speed, gears, part1) {
    if (part1 == 1) {
        for (let i = gears.length - 1; i > 0; i--) {
            var gear2 = gears[i - 1]; var gear1 = gears[i];
            var ratio  = gear1 / gear2;
            speed = speed * ratio;
        }
    }
    else {
        for (let i = 1; i < gears.length; i++) {
            var gear1 = gears[i - 1]; var gear2 = gears[i];
            var ratio  = gear1 / gear2;
            speed = speed * ratio;
        }
    }
    return speed % 1 == 0?  speed : speed + 1;
}

const sample1 = readNumbersFromFile('p1sample1.txt');
const sample2 = readNumbersFromFile('p1sample2.txt');
const input = readNumbersFromFile('puzzle.txt');
const input2 = readNumbersFromFile('puzzle2.txt');
// PART ONE

console.log("Sample 1 Part 1:", getGearRPM(2025, sample1, 0));
console.log("Sample 2 Part 1:", parseInt(getGearRPM(2025, sample2, 0)));
console.log("Input Part 1:", parseInt(getGearRPM(2025, input, 0)));

// PART TWO
console.log("Sample 1 Part 2:", parseInt(getGearRPM(10000000000000 , sample1, 1)));
console.log("Sample 2 Part 2:", parseInt(getGearRPM(10000000000000 , sample2, 1)));
console.log("Input Part 2:", parseInt(getGearRPM(10000000000000 , input2, 1)));

// Part THREE
const sample3 = readNumberPairs('part3Sample.txt');
const sample3A = readNumberPairs('part3Sample2.txt');
const puzzle3 = readNumberPairs('puzzle3.txt');

console.log("Sample 3 Part 3:", parseInt(getdoubleGearRPM(100 , sample3)));
console.log("Sample 3A Part 3:", parseInt(getdoubleGearRPM(100 , sample3A)));
console.log("Puzzle 3 Part 3:", parseInt(getdoubleGearRPM(100 , puzzle3)));
