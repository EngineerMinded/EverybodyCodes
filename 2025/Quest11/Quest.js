// Wayne Mack
// Everybody Codes
// Quest 11

// DAMN: Got all three parts!

const fs = require('fs');

function readNumbersFromFile(filename) {
  const content = fs.readFileSync(filename, 'utf8');

  return content
    .trim()                 // remove leading/trailing whitespace
    .split(/\r?\n/)         // split into lines (handles Windows & Unix)
    .map(line => parseInt(line, 10));  // convert each line to integer
}

// reads a string of space-separated numbers and returns an array of integers
function parseNumbers(str) {
  return str
    .trim()                 // remove leading/trailing spaces
    .split(/\s+/)           // split on one or more spaces
    .map(num => parseInt(num, 10));  // convert each to integer
}

// SWITCH THE PHASE BACK AND FORTH AS NEEDED
function switchPhaseIfNeeded(currentPhase, listOfNumbers) {
    var phase1 = true;
    var phase2 = true;
    for (var i = 1; i < listOfNumbers.length; i++) {
        if (listOfNumbers[i] > listOfNumbers[i - 1]) {phase1 = false;}
        if (listOfNumbers[i] < listOfNumbers[i - 1]) {phase2 = false;}   
    }
    if (phase1) {return true;}
    if (phase2) {return false;}
    return currentPhase;
}

// ARE ALL THE NUMBERS THE SAME?
function flockIsBalanced(listOfNumbers) {
    for (var i = 1; i < listOfNumbers.length; i++) {
        if (listOfNumbers[i] != listOfNumbers[i - 1]) return false; 
    }
    return true;
}

// THIS WASN'T NEEDED AFTER ALL BUT, LEFT IT IN FOR NOW
function reduceNumberListtoLowestNumber(listOfNumbers) {
    let minNumber = Math.min(...listOfNumbers);
    return listOfNumbers.map(num => num - minNumber);
}

// THE ALGORITHM FOR PARTS 1 AND 2
function flockCalculation(listOfNumbers, numberOfRounds, part2) {
    let phase = true;
    let part2FlockBalanced = 0; 
    let multiplier = 1;
    do {
        for (var a = 0; a < numberOfRounds; a++) {
            //multiplier = determineMultipler(listOfNumbers);
            phase = switchPhaseIfNeeded(phase, listOfNumbers);
                if (phase) {
                    for (var i = 1; i < listOfNumbers.length; i++) {
                        if (listOfNumbers[i] < listOfNumbers[i - 1]) {
                            listOfNumbers[i]+= multiplier;
                            listOfNumbers[i - 1]-= multiplier;
                        }
                    }   
                } else {
                    for (var i = 1; i < listOfNumbers.length; i++) {
                        if (listOfNumbers[i] > listOfNumbers[i - 1]) {
                            listOfNumbers[i]-= multiplier;
                            listOfNumbers[i - 1]+= multiplier;
                        }
                    }
            }
        }
        part2FlockBalanced+= multiplier;
    } while (part2 && !flockIsBalanced(listOfNumbers));

    // Answer for Part 2 here:
    if (part2) return part2FlockBalanced;
       
    // Answer for Part 1 here:
    let returnThis = 0;
    for (var i = 0; i < listOfNumbers.length; i++) {
        returnThis += listOfNumbers[i] * (i + 1);
    }
    return returnThis;
}

// WHAT THE HELL? THIS WAS EASIER THAN I THOUGHT!
function part3(listOfNumbers) {
    let meanOfNumbers = listOfNumbers.reduce((a, b) => a + b, 0) / listOfNumbers.length;
    let returnTHis = 0;
    listOfNumbers.forEach(num => {
        if (num > meanOfNumbers)  returnTHis += (num - meanOfNumbers);
    });
    return returnTHis;
}

// PART ONE:
console.log("Sample 1: " ,flockCalculation(parseNumbers("9 1 1 4 9 6"),10, false)); 
console.log("part 1: " ,flockCalculation(parseNumbers("3 2 19 14 18 10"),10, false));

//PART TWO:
console.log("Sample 2: " ,flockCalculation(parseNumbers("9 1 1 4 9 6"),1, true));
console.log("Another Sample 2: " ,flockCalculation(parseNumbers("805 706 179 48 158 150 232 885 598 524 423"),1, true));
console.log("Part 2: " ,flockCalculation((readNumbersFromFile("part2.txt")),1, true));

// Part THREE:
console.log("part 3: " ,part3((readNumbersFromFile("part3.txt"))));
