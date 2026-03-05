// Wayne Mack
// Everybody Codes
// Quest 2

const fs = require('fs');

function readCharArray(path) {
  const text = fs.readFileSync(path, 'utf8');
  return [...text];        // spreads into a character array
}

// Example:
const chars = readCharArray('example1.txt');
console.log(chars); 