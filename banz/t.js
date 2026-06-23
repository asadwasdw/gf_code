//矩阵快速幂求解斐波那契
const mod = BigInt(1e9 + 7);

class Matrix {
    constructor() {
        this.m = Array.from({ length: 4 }, () => Array(4).fill(BigInt(0)));
    }
}

function multiply(a, b) {
    let c = new Matrix();
    for (let i = 1; i < 4; i++) {
        for (let k = 1; k < 4; k++) {
            if (a.m[i][k]) {
                for (let j = 1; j < 4; j++) {
                    if (b.m[k][j]) {
                        c.m[i][j] += a.m[i][k] * b.m[k][j];
                        c.m[i][j] %= mod;
                    }
                }
            }
        }
    }
    return c;
}

function power(a, b) {
    let res = new Matrix();
    for (let i = 1; i < 4; i++) res.m[i][i] = BigInt(1);
    while (b) {
        if (b & 1n) res = multiply(res, a);
        a = multiply(a, a);
        b >>= 1n;
    }
    return res;
}

function solve(n) {
    let t1 = new Matrix();
    t1.m[1][1] = BigInt(1);
    t1.m[1][2] = BigInt(1);
    t1.m[1][3] = BigInt(1);

    let t2 = new Matrix();
    t2.m[2][1] = BigInt(1);
    t2.m[1][2] = BigInt(1);
    t2.m[2][2] = BigInt(1);
    t2.m[2][3] = BigInt(1);
    t2.m[3][3] = BigInt(1);

    let result = multiply(t1, power(t2, n - 1n));
    return result.m[1][1].toString();
}

function main() {
    const t = 30;
    for (let i = 1; i <= t; i++) {
        const n = BigInt(i);
        const result = solve(n);
        console.log(result);
    }
}

main();