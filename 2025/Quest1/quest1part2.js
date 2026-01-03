const fs = require('fs');
const readline = require('readline');

// Path to your input file
const filePath = 'q1p2.txt';

// Create a read stream and interface for line-by-line reading
const rl = readline.createInterface({
  input: fs.createReadStream(filePath),
  crlfDelay: Infinity
});

const example1 = [];

rl.on('line', (line) => {
  // Split each line by commas and trim whitespace
  const words = line.split(',').map(word => word.trim());
  example1.push(words);
});

rl.on('close', () => {
  quest1Part2(example1);
});

function quest1Part2 (data) {
  let words = data[0]; ways = data[1];
  //console.log(words);
  //console.log(ways);

  var num = 0;
  ways.forEach(w => {
     number = parseInt(w.replace(/[^0-9]/g, ''));
     direction = w.replace(/[^a-zA-Z]/g, '');
     if (direction == 'L') {
      num = num - number;
      while  (num < 0) {
        num = num + words.length;
      }
     }
     else {
      num = num + number;
      while (num >= words.length ) {
        num =  num - words.length;
      }
     }
     console.log (words[num]);
  });
  
  
}
