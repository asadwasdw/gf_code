#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using db = double;
constexpr int N = 1e5 + 50, LOGN = 30;
constexpr i64 P = 1e9 + 7, inf = 1e9;

bool s[6][51][N];
vector<int> bit(7);

void solve(){
    int n, m; cin >> n >> m;
    vector<int> ans;
    vector<pair<string, int>> ask(m);
    for (int i = 0; i < m; i++) {
        cin >> ask[i].first >> ask[i].second;
    }
    for (int i = 0; i < bit[n]; i++) {
        bool ok = true;
        auto check = [&](int x, pair<string, int> t) -> bool {
            int val = 0;
            for (int i = 0; i < n; i++) {
                int tmp = (t.first[i] - (x / bit[n - i - 1]) % 10 + 10 - '0') % 10;
                val = val * 10 + tmp;
            }
            // if (s[n][t.second][val]) cout << x << ' ' << val << ' ' << t.first << '\n';
            return s[n][t.second][val];
        };
        for (int j = 0; j < m; j++) {
            if (!check(i, ask[j])) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(i);
    }
    if (ans.size() == 0) {
        cout << "IMPOSSIBLE\n";
    } else if (ans.size() > 1) {
        cout << "MANY\n";
    } else {
        string t = to_string(ans[0]);
        while (t.size() < n) t.insert(t.begin(), '0');
        cout << t << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    bit[0] = 1;
    for (int i = 1; i <= 6; i++) bit[i] = bit[i - 1] * 10;
    for (int i = 1; i <= 5; i++) {
        s[i][0][0] = 1;
        for (int t = 1; t <= 10 * i; t++) {
            for (int j = 0; j < bit[i]; j++) {
                string tmp = to_string(j);
                while (tmp.size() < i) tmp.insert(tmp.begin(), '0');
                for (int l = 0; l < i; l++)
                for (int r = l; r < i; r++) {
                    {
                        int val = 0;
                        for (int k = 0; k < i; k++){
                            val *= 10;
                            if (k >= l && k <= r) val += (tmp[k] - '0' + 1) % 10;
                        }
                        s[i][t][val] |= s[i][t - 1][j];

                    }
                    {
                        int val = 0;
                        for (int k = 0; k < i; k++){
                            val *= 10;
                            if (k >= l && k <= r) val += (tmp[k] - '0' + 9) % 10;
                        }
                        s[i][t][val] |= s[i][t - 1][j];
                    }
                }
            }
            // for (int j = 0; j < bit[i]; j++) cerr << s[i][t][j] << " \n"[j == bit[i] - 1];
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

