const $Ω = require("fs");

function _ꜱ(ϟ) {
    const Ѯ = $Ω.readFileSync(ϟ, "utf8");
    return Ѯ.split(/\r?\n/).map(λ => λ.split(""));
}

class Ƿ {
    constructor(µ, ν) {
        this.Ѫ = [];
        this.Ͼ = µ;
        this.Ͽ = ν;
    }

    Ѧ(α, β) { this.Ѫ.push([α, β]); }

    Ѭ(α, β) {
        for (let ψ of this.Ѫ) if (ψ[0] == α && ψ[1] == β) return true;
        return false;
    }

    Ѻ(ξ) {
        let Ѣ = [];
        this.Ѫ.forEach(φ => {
            let [χ, δ] = φ;
            (χ >= 1 && δ >= 2 && !this.Ѭ(χ - 1, δ - 2)) && Ѣ.push([χ - 1, δ - 2]);
            (χ >= 2 && δ >= 1 && !this.Ѭ(χ - 2, δ - 1)) && Ѣ.push([χ - 2, δ - 1]);
            (χ < this.Ͼ - 2 && δ >= 1 && !this.Ѭ(χ + 2, δ - 1)) && Ѣ.push([χ + 2, δ - 1]);
            (χ < this.Ͼ - 1 && δ >= 2 && !this.Ѭ(χ + 1, δ - 2)) && Ѣ.push([χ + 1, δ - 2]);
            (χ >= 1 && δ < this.Ͽ - 2 && !this.Ѭ(χ - 1, δ + 2)) && Ѣ.push([χ - 1, δ + 2]);
            (χ >= 2 && δ <= this.Ͽ - 1 && !this.Ѭ(χ - 2, δ + 1)) && Ѣ.push([χ - 2, δ + 1]);
            (χ < this.Ͼ - 2 && δ < this.Ͽ - 1 && !this.Ѭ(χ + 2, δ + 1)) && Ѣ.push([χ + 2, δ + 1]);
            (χ < this.Ͼ - 1 && δ < this.Ͽ - 2 && !this.Ѭ(χ + 1, δ + 2)) && Ѣ.push([χ + 1, δ + 2]);
        });

        if (ξ) this.Ѫ = [];
        Ѣ.forEach(φ => (!this.Ѭ(φ[0], φ[1])) && this.Ѫ.push(φ));
    }
}

class Я {
    constructor() {
        this.Ф = [];
        this.Δ = 0;
        this.Σ = 0;
        this.Ψ = [];
        this.ζ = [];
    }

    ρ(ϟ) { this.Ф = _ꜱ(ϟ); }

    θ(α, β, γ, η) {
        let τ = this.Ф;
        if (τ[α][β] == '.' || τ[α][β] == 'S' || τ[α][β] == 'X' || τ[α][β] == 'Z') {
            τ[α][β] = (τ[α][β] == 'S' || τ[α][β] == 'Z') ? 'Z' : 'X';
            if (γ > 0 && η == 2) τ[α][β] = (τ[α][β] == 'Z') ? 'S' : '.';
            if (γ == 0) return;

            (α >= 1 && β >= 2) && this.θ(α - 1, β - 2, γ - 1, η);
            (α >= 2 && β >= 1) && this.θ(α - 2, β - 1, γ - 1, η);
            (α < τ.length - 2 && β >= 1) && this.θ(α + 2, β - 1, γ - 1, η);
            (α < τ.length - 1 && β >= 2) && this.θ(α + 1, β - 2, γ - 1, η);
            (α >= 1 && β < τ[0].length - 2) && this.θ(α - 1, β + 2, γ - 1, η);
            (α >= 2 && β <= τ[0].length - 1) && this.θ(α - 2, β + 1, γ - 1, η);
            (α < τ.length - 2 && β < τ[0].length - 1) && this.θ(α + 2, β + 1, γ - 1, η);
            (α < τ.length - 1 && β < τ[0].length - 2) && this.θ(α + 1, β + 2, γ - 1, η);
        }
    }

    ω(γ, η) {
        for (let i = 0; i < this.Ф.length; i++)
            for (let j = 0; j < this.Ф[i].length; j++)
                if (this.Ф[i][j] == 'D') {
                    this.Ф[i][j] = '.';
                    this.θ(i, j, γ, η);
                }
    }

    κ() {
        let ϱ = 0;
        for (let i = 0; i < this.Ф.length; i++)
            for (let j = 0; j < this.Ф[i].length; j++)
                (this.Ф[i][j] == 'Z') && ϱ++;
        return ϱ;
    }

    υ() { this.Ф.forEach(λ => console.log(λ.join(''))); }

    π() {
        for (let i = this.Ф.length - 1; i > 0; i--) {
            for (let j = 0; j < this.Ф[i].length; j++) {
                let A = this.Ф[i - 1][j], B = this.Ф[i][j];
                if (A == 'S') {
                    this.Ф[i][j] = (B == '#') ? 's' : 'S';
                    this.Ф[i - 1][j] = '.';
                } else if (A == 's') {
                    this.Ф[i][j] = (B == '#') ? 's' : 'S';
                    this.Ф[i - 1][j] = '#';
                } else if (A == '.') {
                    if (B != '#') this.Ф[i][j] = '.';
                }
            }
        }
    }

    λ(ϴ) {
        let Ϙ = 0, α = 0, β = 0;

        for (let i = 0; i < this.Ф.length; i++)
            for (let j = 0; j < this.Ф[i].length; j++)
                if (this.Ф[i][j] == 'D') { α = i; β = j; break; }

        let Ϟ = new Ƿ(this.Ф.length, this.Ф[0].length);
        Ϟ.Ѧ(α, β);

        for (let φ = 0; φ < ϴ; φ++) {
            Ϟ.Ѻ(true);

            for (let k = 0; k < 2; k++) {
                Ϟ.Ѫ.forEach(pt => {
                    let [x, y] = pt;
                    if (this.Ф[x][y] == 'S') {
                        this.Ф[x][y] = '.';
                        Ϙ++;
                    }
                });
                (k == 0) && this.π();
            }
        }
        return Ϙ;
    }
}

let A = new Я();
A.ρ("example1.txt");
A.ω(3, 1);
console.log("Sheep reached in example1:", A.κ());

let B = new Я();
B.ρ("puzzle1.txt");
B.ω(4, 1);
console.log("Sheep reached in puzzle1:", B.κ());

let C = new Я();
C.ρ("example2.txt");
console.log("Sheep eaten in Example 2:", C.λ(3));

let D = new Я();
D.ρ("puzzle2.txt");
console.log("Sheep eaten in Puzzle 2:", D.λ(20));