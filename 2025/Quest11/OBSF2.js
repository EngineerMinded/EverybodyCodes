const φ = require('fs');

function α(β) {
    const γ = φ.readFileSync(β, 'utf8');
    return γ.trim().split(/\r?\n/).map(δ => parseInt(δ, 10));
}

function ε(ζ) {
    return ζ.trim().split(/\s+/).map(η => parseInt(η, 10));
}

function θ(ι, κ) {
    let λ = true, μ = true;
    for (let ν = 1; ν < κ.length; ν++) {
        if (κ[ν] > κ[ν - 1]) λ = false;
        if (κ[ν] < κ[ν - 1]) μ = false;
    }
    if (λ) return true;
    if (μ) return false;
    return ι;
}

function ξ(ο) {
    for (let π = 1; π < ο.length; π++) {
        if (ο[π] !== ο[π - 1]) return false;
    }
    return true;
}

function ρ(σ) {
    let τ = Math.min(...σ);
    return σ.map(υ => υ - τ);
}

function φλ(χ, ψ, ω) {
    let α1 = true;
    let β1 = 0;
    let γ1 = 1;

    do {
        for (let δ1 = 0; δ1 < ψ; δ1++) {
            α1 = θ(α1, χ);

            if (α1) {
                for (let ε1 = 1; ε1 < χ.length; ε1++) {
                    if (χ[ε1] < χ[ε1 - 1]) {
                        χ[ε1] += γ1;
                        χ[ε1 - 1] -= γ1;
                    }
                }
            } else {
                for (let ζ1 = 1; ζ1 < χ.length; ζ1++) {
                    if (χ[ζ1] > χ[ζ1 - 1]) {
                        χ[ζ1] -= γ1;
                        χ[ζ1 - 1] += γ1;
                    }
                }
            }
        }
        β1 += γ1;
    } while (ω && !ξ(χ));

    if (ω) return β1;

    let η1 = 0;
    for (let θ1 = 0; θ1 < χ.length; θ1++) {
        η1 += χ[θ1] * (θ1 + 1);
    }
    return η1;
}

function ι1(κ1) {
    let λ1 = κ1.reduce((μ1, ν1) => μ1 + ν1, 0) / κ1.length;
    let ξ1 = 0;
    κ1.forEach(ο1 => {
        if (ο1 > λ1) ξ1 += (ο1 - λ1);
    });
    return ξ1;
}

// PART 1
console.log("Sample 1:", φλ(ε("9 1 1 4 9 6"), 10, false));
console.log("Part 1:", φλ(ε("3 2 19 14 18 10"), 10, false));

// PART 2
console.log("Sample 2:", φλ(ε("9 1 1 4 9 6"), 1, true));
console.log("Another Sample 2:", φλ(ε("805 706 179 48 158 150 232 885 598 524 423"), 1, true));
console.log("Part 2:", φλ(α("part2.txt"), 1, true));

// PART 3
console.log("Part 3:", ι1(α("part3.txt")));