#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 调大 maxN 应对插入 '{' 后的节点增加
const int maxN = 6e6 + 10; 
const int ALPHA = 27;       
int trie[maxN][ALPHA];
int val[maxN];         
int fail[maxN];      
int cnt;                

void init_node(int u) {
    memset(trie[u], 0, sizeof(trie[u]));
    val[u] = 0;
}

// 构建 AC 自动机（Trie 图优化 + Fail 树上贡献直接累加）
void build() {
    queue<int> q;
    for (int i = 0; i < ALPHA; ++i) {
        if (trie[0][i]) {
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // 核心步骤：直接将 fail 指针指向的节点的答案数量，累加到当前节点
        val[u] += val[fail[u]];
        
        for (int i = 0; i < ALPHA; ++i) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i]; // 经典 Trie 图连向 fail 的对应子节点
                q.push(trie[u][i]);
            } else {
                trie[u][i] = trie[fail[u]][i]; // 补全状态转移，避免运行时跳 fail 链
            }
        }
    }
}

// 单词匹配，单次查询复杂度严格 O(|txt|)
ll match(const string& txt) {
    ll res = 0;
    int p = 0;
    for (char c : txt) {
        int idx = (c == '{') ? 26 : (c - 'a');
        p = trie[p][idx];
        res += val[p]; // 已经完成预处理，这里直接 O(1) 累加
    }
    return res;
}

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    cnt = 0;
    init_node(0);
    
    for (int i = 1; i <= n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        int m = s1.size();
        int l = 0;
        while (l < m && s1[l] == s2[l]) l++;
        int r = m - 1;
        while (r >= l && s1[r] == s2[r]) r--;
        
        string pattern;
        for (int k = 0; k < l; ++k) pattern += s1[k];
        pattern += '{';
        for (int k = l; k <= r; ++k) pattern += s1[k];
        for (int k = l; k <= r; ++k) pattern += s2[k];
        pattern += '{';
        for (int k = r + 1; k < m; ++k) pattern += s1[k];
        
        int p = 0;
        for (char c : pattern) {
            int idx = (c == '{') ? 26 : (c - 'a');
            if (!trie[p][idx]) {
                init_node(++cnt);
                trie[p][idx] = cnt;
            }
            p = trie[p][idx];
        }
        val[p]++; // 正确处理相同模式的多个替换规则，累加计数
    }
    
    build();
    
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int m = t1.size();
        if (m != t2.size()) {
            cout << "0\n";
            continue;
        }
        int l = 0;
        while (l < m && t1[l] == t2[l]) l++;
        int r = m - 1;
        while (r >= l && t1[r] == t2[r]) r--;
        
        string target;
        for (int k = 0; k < l; ++k) target += t1[k];
        target += '{';
        for (int k = l; k <= r; ++k) target += t1[k];
        for (int k = l; k <= r; ++k) target += t2[k];
        target += '{';
        for (int k = r + 1; k < m; ++k) target += t1[k];
        
        ll res = match(target);
        cout << res << '\n';
    }
    return 0;
}