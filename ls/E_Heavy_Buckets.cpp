#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N = 3e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[N];
vector<int> fadj[N];

int d[N];
int nxt[N][40];
int sum[N][40];

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        adj[i].push_back(x);
        nxt[i][0] = x;
        sum[i][0] = i;
    }


    for(int j = 1; j < 32; j ++) {
        for(int i = 1; i <= n; i ++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[nxt[i][j - 1]][j - 1];
        }
    }

    // cout << nxt[1][0] << " " << sum[1][0] << endl;

    while(q --) {
        int T, b;
        cin >> T >> b;
        int now = b;
        long long ans = 0;
        for(int t = 31; ~t; t --) {
            if(T >= (1ll << t)) {
                T -= (1ll << t);
                // cout << T << " " << now << " " << t << " " << sum[now][t] << endl;
                ans += sum[now][t];
                now = nxt[now][t];
            }
        }

        cout << ans << endl;
    }

    

   





}

signed main() {

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}