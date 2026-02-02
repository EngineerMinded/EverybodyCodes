def α(β, γ=False):
    δ = []
    with open(β, "r") as ε:
        for ζ in ε:
            η = ζ.strip().split(",")
            for θ in η:
                θ = θ.strip()
                if "-" in θ:
                    if not γ:
                        ι, κ = θ.split("-")
                        ι, κ = int(ι), int(κ)
                        λ = []
                        for μ in range(ι, κ + 1):
                            λ.append(μ)
                        δ.append(λ)
                    else:
                        δ.append(θ)
                elif θ.isdigit():
                    δ.append(int(θ))
    return δ

def ν(ξ, ο=False):
    π = []
    if not ο:
        π.append(1)
    else:
        π.append("1-1")
    ρ = []
    for σ in range(len(ξ)):
        if (σ % 2) == 0:
            if (not ο) and isinstance(ξ[σ], type([])):
                for τ in ξ[σ]:
                    π.append(τ)
            else:
                π.append(ξ[σ])
        else:
            if (not ο) and isinstance(ξ[σ], type([])):
                for τ in ξ[σ]:
                    ρ.append(τ)
            else:
                ρ.append(ξ[σ])
    for υ in range(len(ρ) - 1, -1, -1):
        π.append(ρ[υ])
    return π

def φ(χ, ψ):
    ψ = ψ % len(χ)
    return χ[ψ]

def ω(χ, ψ):

    def αα(ββ):
        γγ, δδ = ββ.split('-')
        return abs(int(γγ) - int(δδ)) + 1

    def εε(ζζ):
        ηη = 0
        for θθ in ζζ:
            ηη += αα(θθ)
        return ηη

    def ιι(κκ, λλ):
        μμ, νν = κκ.replace(" ", "").split('-')
        return int(νν) - λλ

    ψ = ψ % εε(χ)
    οο = 0
    while ψ > αα(χ[οο]):
        ψ -= αα(χ[οο])
        οο += 1
    if οο >= len(χ):
        return -1
    return ιι(χ[οο], ψ)

ε1 = α("example1.txt")
ε1 = ν(ε1)
print("Example 1: " + str(φ(ε1, 2025)))

π1 = α("part1.txt")
π1 = ν(π1)
print("Part 1: " + str(φ(π1, 2025)))

ε2 = α("example2.txt")
ε2 = ν(ε2)
print("Example 2: " + str(φ(ε2, 20252025)))

π2 = α("part2.txt")
π2 = ν(π2)
print("Part 2: " + str(φ(π2, 20252025)))

π2 = α("part2.txt", True)
π2 = ν(π2, True)
print("Part 2 with new function: " + str(ω(π2, 20252025)))

π3 = α("part3.txt", True)
π3 = ν(π3, True)
print("Part 3: " + str(ω(π3, 202520252025)))