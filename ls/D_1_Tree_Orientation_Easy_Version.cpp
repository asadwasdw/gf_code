#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 检查集合 i 是否包含集合 j (S_j ⊆ S_i)
bool contains(int i, int j, int n, const vector<string>& adj) {
    for (int k = 0; k < n; ++k) {
        if (adj[j][k] == '1' && adj[i][k] == '0') return false;
    }
    return true;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<string> adj(n);
    for (int i = 0; i < n; ++i) cin >> adj[i];

    // 1. 检查自环和基本冲突 (i能到j且j能到i，则不是树)
    for (int i = 0; i < n; ++i) {
        if (adj[i][i] == '0') { cout << "No" << endl; return; }
        for (int j = 0; j < n; ++j) {
            if (i != j && adj[i][j] == '1' && adj[j][i] == '1') {
                cout << "No" << endl; return;
            }
        }
    }

    vector<pair<int, int>> edges;
    
    // 2. 遍历所有 i, j 对，寻找可能的边
    // 如果 adj[i][j] == '1'，说明有一条从 i 到 j 的路径
    // 如果这条路径是直接边，那么在所有 i 能到的节点 k 中，
    // j 应该是那个“包含可达集合最大”的节点（除去 i 本身）
    for (int j = 0; j < n; ++j) {
        int parent = -1;
        int max_reach = -1;
        for (int i = 0; i < n; ++i) {
            if (i == j || adj[i][j] == '0') continue;
            
            // i 是 j 的祖先。我们需要找最近的祖先。
            // 最近祖先 i 的可达集合 S_i 在所有祖先中应该是最小的。
            int current_reach = 0;
            for(int k=0; k<n; ++k) if(adj[i][k] == '1') current_reach++;
            
            if (parent == -1 || current_reach < max_reach) {
                max_reach = current_reach;
                parent = i;
            }
        }
        if (parent != -1) {
            edges.push_back({parent + 1, j + 1});
        }
    }

    // 3. 验证是否构成了 n-1 条边
    // 注意：如果是森林或不满足树的性质，需要额外判定
    if (edges.size() != n - 1) {
        // 这里需要更复杂的判定，但对于 Easy Version，
        // 核心逻辑在于：每个节点（除了根）都有且只有一个入边
        cout << "No" << endl;
        return;
    }

    // 4. 最终验证：用构造出的边跑一次闭包，看是否与输入 adj 一致
    // 这一步能排除掉所有非法构造
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dist[i][i] = 1;
    for (auto& e : edges) dist[e.first - 1][e.second - 1] = 1;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] && dist[k][j]) dist[i][j] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((dist[i][j] ? '1' : '0') != adj[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
    for (auto& e : edges) cout << e.first << " " << e.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}