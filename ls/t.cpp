#include <bits/stdc++.h>
using namespace std;

// 递归版本：模拟抹平余数并整除的过程

int cnt1 = 0, cnt2 = 0;
int f(int n, int k) {
    if (n < k) {
        return 0;
    } else if (n % k == 0) {
        return 1 + f(n / k, k);
    } else {
        cnt2 ++;
        return f(n - 1, k);
    }
}

// 迭代版本：直接利用 C++ 整数除法的向下取整特性
int g(int n, int k) {
    int ans = 0;
    while (n >= k) {
        ans++;
        n /= k;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << f(n, k) << " " << g(n, k) << endl;

    cout << __builtin_popcount(n) << " " << cnt2 << endl;
    
    return 0;
}