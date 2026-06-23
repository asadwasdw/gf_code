#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

long long fact[200005], invFact[200005];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) fact[i] = (fact[i - 1] * i) % 998244353;
    invFact[200000] = modInverse(fact[200000]);
    for (int i = 199999; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % 998244353;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % 998244353 * invFact[n - r] % 998244353;
}

int main() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    
    // diffA 记录必须选 A 的人数变化，diffBoth 记录可选 A 可选 B 的人数变化
    // validCount 记录当前 k 有多少玩家是“可分配”的（即满足 A 或 B 之一）
    vector<int> diffA(N + 2, 0), diffBoth(N + 2, 0), validCount(N + 2, 0);

    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        int LA = L[i], RA = R[i];
        int LB = N - R[i], RB = N - L[i];

        // 玩家 i 能够被分配的 k 范围是 [LA, RA] U [LB, RB]
        // 我们利用差分标记这些区间
        auto add_range = [&](vector<int>& vec, int l, int r) {
            if (l > r) return;
            vec[max(0, l)]++;
            vec[min(N + 1, r + 1)]--;
        };

        // 逻辑：
        // 1. 只要 k 落在 [LA, RA] 或 [LB, RB]，该玩家就是合法的
        // 2. 如果 k 只落在 [LA, RA]，必须选 A
        // 3. 如果 k 同时落在 [LA, RA] 和 [LB, RB]，A/B 皆可
        
        // 统计合法 k 的覆盖次数
        if (LA <= RA && LB <= RB && max(LA, LB) <= min(RA, RB)) {
            // 区间重叠：[min(LA, LB), max(RA, RB)]
            add_range(validCount, min(LA, LB), max(RA, RB));
        } else {
            // 区间不重叠
            add_range(validCount, LA, RA);
            add_range(validCount, LB, RB);
        }

        // 统计必须选 A 和 两者皆可 的差分
        // 这里简化逻辑：
        // C_both(k) 是 k 同时在两个区间的人数
        // C_A_total(k) 是 k 在 [LA, RA] 的总人数（包含必须选 A 和 两者皆可）
        // 那么 选 A 的方案就是从 C_both 中选人来补齐 k - (C_A_total - C_both)
    }

    // 实际上，更稳妥的差分做法是对每个 k 统计：
    // cntA: 落在 [LA, RA] 的玩家数
    // cntB: 落在 [LB, RB] 的玩家数
    // 只有当 cntA + cntB - (同时在两边的人数) == N 时，k 才合法
    // 此时 C_both = 同时在两边的人数, C_mustA = cntA - C_both
    // 目标是选出 x 个人进 A，使得 C_mustA + x = k，即 x = k - C_mustA
    
    // 重新修正差分逻辑
    vector<int> d_cntA(N + 2, 0), d_cntB(N + 2, 0), d_cntBoth(N + 2, 0);
    for (int i = 0; i < N; i++) {
        int LA = L[i], RA = R[i];
        int LB = N - R[i], RB = N - L[i];
        
        auto add = [&](vector<int>& d, int l, int r) {
            if (l <= r && l <= N) {
                d[max(0, l)]++;
                d[min(N + 1, r + 1)]--;
            }
        };
        add(d_cntA, LA, RA);
        add(d_cntB, LB, RB);
        add(d_cntBoth, max(LA, LB), min(RA, RB));
    }

    precompute();
    long long ans = 0;
    int curA = 0, curB = 0, curBoth = 0;

    for (int k = 1; k <= N - 1; k++) {
        curA += d_cntA[k];
        curB += d_cntB[k];
        curBoth += d_cntBoth[k];

        // 检查是否所有 N 个球员都能找到归宿
        if (curA + curB - curBoth == N) {
            int mustA = curA - curBoth;
            // 组合数：从 curBoth 个“哪里都能去”的人里，选出 (k - mustA) 个去 A 队
            ans = (ans + nCr(curBoth, k - mustA)) % 998244353;
        }
    }

    cout << ans << endl;

    return 0;
}