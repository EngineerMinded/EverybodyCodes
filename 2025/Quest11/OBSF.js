// Уэйн Мак


const фс = require('fs');

function читатьЧисла(имяФайла) {
    const содержимое = фс.readFileSync(имяФайла, 'utf8');
    return содержимое.trim().split(/\r?\n/).map(стр => parseInt(стр, 10));
}

function парсЧисла(строка) {
    return строка.trim().split(/\s+/).map(н => parseInt(н, 10));
}

function переключитьФазу(текущаяФаза, список) {
    let φ1 = true, φ2 = true;
    for (let ι = 1; ι < список.length; ι++) {
        if (список[ι] > список[ι - 1]) φ1 = false;
        if (список[ι] < список[ι - 1]) φ2 = false;
    }
    if (φ1) return true;
    if (φ2) return false;
    return текущаяФаза;
}

function стадоСбалансировано(список) {
    for (let κ = 1; κ < список.length; κ++) {
        if (список[κ] !== список[κ - 1]) return false;
    }
    return true;
}

function снизитьДоМинимального(список) {
    let мин = Math.min(...список);
    return список.map(χ => χ - мин);
}

function расчётСтада(список, раунды, часть2) {
    let фаза = true;
    let сумма2 = 0;
    let μ = 1;

    do {
        for (let α = 0; α < раунды; α++) {
            фаза = переключитьФазу(фаза, список);

            if (фаза) {
                for (let β = 1; β < список.length; β++) {
                    if (список[β] < список[β - 1]) {
                        список[β] += μ;
                        список[β - 1] -= μ;
                    }
                }
            } else {
                for (let γ = 1; γ < список.length; γ++) {
                    if (список[γ] > список[γ - 1]) {
                        список[γ] -= μ;
                        список[γ - 1] += μ;
                    }
                }
            }
        }
        сумма2 += μ;
    } while (часть2 && !стадоСбалансировано(список));

    if (часть2) return сумма2;

    let итог = 0;
    for (let δ = 0; δ < список.length; δ++) {
        итог += список[δ] * (δ + 1);
    }
    return итог;
}

function часть3(список) {
    let ср = список.reduce((α, β) => α + β, 0) / список.length;
    let ρ = 0;
    список.forEach(ν => {
        if (ν > ср) ρ += (ν - ср);
    });
    return ρ;
}

// PART 1
console.log("Sample 1:", расчётСтада(парсЧисла("9 1 1 4 9 6"), 10, false));
console.log("Part 1:", расчётСтада(парсЧисла("3 2 19 14 18 10"), 10, false));

// PART 2
console.log("Sample 2:", расчётСтада(парсЧисла("9 1 1 4 9 6"), 1, true));
console.log("Another Sample 2:", расчётСтада(парсЧисла("805 706 179 48 158 150 232 885 598 524 423"), 1, true));
console.log("Part 2:", расчётСтада(читатьЧисла("part2.txt"), 1, true));

// PART 3
console.log("Part 3:", часть3(читатьЧисла("part3.txt")));