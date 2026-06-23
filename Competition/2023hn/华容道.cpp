#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

long long n,m,x,y,r1,c1,r2,c2;

void Rotate(long long &r, long long &c) {
    double t = c; c = n+1-r; r = t;
}

void RotateAll() {
    while(r2<r1 || c2<c1) {
        Rotate(x,y);
        Rotate(r1,c1);
        Rotate(r2,c2);
        long long t = n; n = m; m = t;
    }
}

long long Distance(long long r1, long long c1, long long r2, long long c2) {
    return abs(r1-r2) + abs(c1-c2);
}

long long BlankMove() {

    int d1 = Distance(x, y, r1, c1 + 1);
    int d2 = Distance(x, y, r1 + 1, c1);
    if(x == r1 && y < c1) d1 += 2;
    if(y == c1 && x < r1) d2 += 2;
    if(c2 - c1 == r2 - r1) return min(d1, d2);
    if(c2-c1 > r2-r1) return d1;
    return d2;
}

long long ChessMove() {
    if(c2==c1 || r2==r1) return 1+5*(Distance(r1,c1,r2,c2)-1); //直线
    if(r2-r1 == c2-c1) return 1+3*(Distance(r1,c1,r2,c2)-1); //斜对角
    return 1+3*(min(r2-r1,c2-c1)*2-1) + 2 + 1 + 5*(Distance(r1,c1,r2,c2)-min(r2-r1,c2-c1)*2-1); //对角+直线
}

int main() {
    // while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &n, &m, &x, &y, &r1, &c1, &r2, &c2)!=EOF) {
    //     if(c1==c2 && r1==r2) printf("0\n");
    //     else {
    //         RotateAll();
    //         printf("%lld\n", BlankMove() + ChessMove());
    //     }
    // }

    n=2;
    m=3;
    x=1,y=2;
    Rotate(x,y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
