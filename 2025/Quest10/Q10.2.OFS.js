const ᚠᛇᚻ = require("fs");

function Ⴀ​Ⴁ​Ⴂ(ֆ) {
    const ᴥ = ᚠᛇᚻ.readFileSync(ֆ,"utf8");
    return ᴥ.split(/\r?\n/).map(ԓ=>ԓ.split(""));
}

class ჻ {
    constructor(ლ,მ){
        this.Ⴔ = [];
        this.Ⴕ = ლ;
        this.Ⴖ = მ;
    }

    ჼ(ა,ბ){ this.Ⴔ.push([ა,ბ]); }

    ჽ(ა,ბ){
        for (let ϗ of this.Ⴔ)
            if (ϗ[0]==ა && ϗ[1]==ბ) return true;
        return false;
    }

    ჾ(ⴲ){
        let Ϙ = [];
        this.Ⴔ.forEach(ϙ=>{
            let [χ,δ] = ϙ;
            (χ>=1&&δ>=2&&!this.ჽ(χ-1,δ-2))&&Ϙ.push([χ-1,δ-2]);
            (χ>=2&&δ>=1&&!this.ჽ(χ-2,δ-1))&&Ϙ.push([χ-2,δ-1]);
            (χ<this.Ⴕ-2&&δ>=1&&!this.ჽ(χ+2,δ-1))&&Ϙ.push([χ+2,δ-1]);
            (χ<this.Ⴕ-1&&δ>=2&&!this.ჽ(χ+1,δ-2))&&Ϙ.push([χ+1,δ-2]);
            (χ>=1&&δ<this.Ⴖ-2&&!this.ჽ(χ-1,δ+2))&&Ϙ.push([χ-1,δ+2]);
            (χ>=2&&δ<=this.Ⴖ-1&&!this.ჽ(χ-2,δ+1))&&Ϙ.push([χ-2,δ+1]);
            (χ<this.Ⴕ-2&&δ<this.Ⴖ-1&&!this.ჽ(χ+2,δ+1))&&Ϙ.push([χ+2,δ+1]);
            (χ<this.Ⴕ-1&&δ<this.Ⴖ-2&&!this.ჽ(χ+1,δ+2))&&Ϙ.push([χ+1,δ+2]);
        });

        ⴲ && (this.Ⴔ = []);
        Ϙ.forEach(ϙ=>!this.ჽ(ϙ[0],ϙ[1])&&this.Ⴔ.push(ϙ));
    }
}

class Ϟ {
    constructor(){
        this.ᚦ = [];
        this.ᚧ = 0;
        this.ᚨ = 0;
        this.ᚩ = [];
        this.ᚪ = [];
    }

    ᛒ(ֆ){ this.ᚦ = Ⴀ​Ⴁ​Ⴂ(ֆ); }

    ᛓ(ა,ბ,γ,η){
        let Ҩ = this.ᚦ;
        if (Ҩ[ა][ბ]=='.'||Ҩ[ა][ბ]=='S'||Ҩ[ა][ბ]=='X'||Ҩ[ა][ბ]=='Z'){
            Ҩ[ა][ბ] = (Ҩ[ა][ბ]=='S'||Ҩ[ა][ბ]=='Z')?'Z':'X';
            (γ>0&&η==2)&&(Ҩ[ა][ბ]=(Ҩ[ა][ბ]=='Z'?'S':'.'));
            if (γ==0) return;

            (ა>=1&&ბ>=2)&&this.ᛓ(ა-1,ბ-2,γ-1,η);
            (ა>=2&&ბ>=1)&&this.ᛓ(ა-2,ბ-1,γ-1,η);
            (ა<Ҩ.length-2&&ბ>=1)&&this.ᛓ(ა+2,ბ-1,γ-1,η);
            (ა<Ҩ.length-1&&ბ>=2)&&this.ᛓ(ა+1,ბ-2,γ-1,η);
            (ა>=1&&ბ<Ҩ[0].length-2)&&this.ᛓ(ა-1,ბ+2,γ-1,η);
            (ა>=2&&ბ<=Ҩ[0].length-1)&&this.ᛓ(ა-2,ბ+1,γ-1,η);
            (ა<Ҩ.length-2&&ბ<Ҩ[0].length-1)&&this.ᛓ(ა+2,ბ+1,γ-1,η);
            (ა<Ҩ.length-1&&ბ<Ҩ[0].length-2)&&this.ᛓ(ა+1,ბ+2,γ-1,η);
        }
    }

    ᛔ(γ,η){
        for (let i=0;i<this.ᚦ.length;i++)
            for (let j=0;j<this.ᚦ[i].length;j++)
                if (this.ᚦ[i][j]=='D'){
                    this.ᚦ[i][j]='.';
                    this.ᛓ(i,j,γ,η);
                }
    }

    ᛕ(){
        let ϡ=0;
        for (let i=0;i<this.ᚦ.length;i++)
            for (let j=0;j<this.ᚦ[i].length;j++)
                (this.ᚦ[i][j]=='Z')&&ϡ++;
        return ϡ;
    }

    ᛖ(){ this.ᚦ.forEach(r=>console.log(r.join(''))); }

    ᛗ(){
        for (let i=this.ᚦ.length-1;i>0;i--)
            for (let j=0;j<this.ᚦ[i].length;j++){
                let A=this.ᚦ[i-1][j],B=this.ᚦ[i][j];
                A=='S'?(this.ᚦ[i][j]=(B=='#'?'s':'S'),this.ᚦ[i-1][j]='.'):
                A=='s'?(this.ᚦ[i][j]=(B=='#'?'s':'S'),this.ᚦ[i-1][j]='#'):
                A=='.'&&(B!='#')&&(this.ᚦ[i][j]='.');
            }
    }

    ᛘ(ϴ){
        let ϙ=0,ა=0,ბ=0;

        for (let i=0;i<this.ᚦ.length;i++)
            for (let j=0;j<this.ᚦ[i].length;j++)
                if (this.ᚦ[i][j]=='D'){ა=i;ბ=j;break;}

        let Ϟ = new ჻(this.ᚦ.length,this.ᚦ[0].length);
        Ϟ.ჼ(ა,ბ);

        for (let φ=0;φ<ϴ;φ++){
            Ϟ.ჾ(true);

            for (let k=0;k<2;k++){
                Ϟ.Ⴔ.forEach(pt=>{
                    let[x,y]=pt;
                    if (this.ᚦ[x][y]=='S'){
                        this.ᚦ[x][y]='.';
                        ϙ++;
                    }
                });
                (k==0)&&this.ᛗ();
            }
        }
        return ϙ;
    }
}

let ᚱ=new Ϟ();
ᚱ.ᛒ("example1.txt");
ᚱ.ᛔ(3,1);
console.log("Sheep reached in example1:",ᚱ.ᛕ());

let ᚲ=new Ϟ();
ᚲ.ᛒ("puzzle1.txt");
ᚲ.ᛔ(4,1);
console.log("Sheep reached in puzzle1:",ᚲ.ᛕ());

let ᚳ=new Ϟ();
ᚳ.ᛒ("example2.txt");
ᚳ.ᛖ();
console.log("Sheep eaten in Example 2:",ᚳ.ᛘ(3));

let ᚴ=new Ϟ();
ᚴ.ᛒ("puzzle2.txt");
console.log("Sheep eaten in Puzzle 2:",ᚴ.ᛘ(20));