#include <bits/stdc++.h>
using namespace std;

int n;
int m[4000][4000], s[4000][4000], r[4000], c[4000];

void select(int i, int j) {
    s[i][j] ^= 1;
    r[i] += m[i][j], c[j] += m[i][j];
    m[i][j] = -m[i][j];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::string s; std::cin >> s;
        for(int j = 0; j < n; ++j)
            m[i][j] = (s[j] == '+' ? 1 : -1);
    }
    
    for(int i = 0; i < n; ++i) std::cin >> r[i], r[i] = -r[i];
    for(int i = 0; i < n; ++i) std::cin >> c[i], c[i] = -c[i];

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
        if(m[i][j] > 0) select(i, j); //先选所有的+

    for(int i = 0; i < n; ++i) if(c[i] < 0 || r[i] < 0) // 数目不够
        return std::cout << "No\n", 0;
    
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) std::cout << s[i][j];
    //     std::cout << "\n";
    // }

    std::vector<int> rr(n), cc(n);
    for(int i = 0; i < n; ++i) rr[i] = cc[i] = i;
    std::sort(rr.begin(), rr.end(), [](int x, int y) {
        return r[x] > r[y];
    });

    for(int i: rr) {
        std::sort(cc.begin(), cc.end(), [](int x, int y) {
            return c[x] > c[y];
        });
        for(int j: cc) {
            if(r[i] <= 0) break;
            if(c[j] > 0) select(i, j);
        }
    }

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < n; ++j) std::cout << s[i][j];
    //     std::cout << "\n";
    // }
    // for(int i = 0; i < n; ++i) std::cerr << c[i] << char(i == n - 1 ? 10 : 32); 
    // for(int i = 0; i < n; ++i) std::cerr << r[i] << char(i == n - 1 ? 10 : 32);

    for(int i = 0; i < n; ++i) if(c[i] || r[i]) return std::cout << "No\n", 0;

    std::cout << "Yes\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) std::cout << s[i][j];
        std::cout << "\n";
    }

    return 0;
}

