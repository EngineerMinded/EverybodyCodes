const fs = require("fs");

function readFileTo2DCharArray(filename) {
    const text = fs.readFileSync(filename, "utf8");

    // Split into lines, then split each line into characters
    const grid = text
        .split(/\r?\n/)        // handle Windows + Unix line endings
        .map(line => line.split(""));  // convert each line into an array of chars

    return grid;
}
