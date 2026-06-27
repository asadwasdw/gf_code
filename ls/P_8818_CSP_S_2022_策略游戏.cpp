#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int sta[4][N][20];
int stb[2][N][20];
int lg2[N];
int n, m;
int a[N], b[N];

void init() {
    for(int i = 2; i < N; i ++) {
        lg2[i] = lg2[i >> 1] + 1;
    }

    for(int i = 1; i <= n; i ++) {
        sta[0][i][0] = a[i]; // 最大值
        sta[1][i][0] = a[i]; // 最小值
        sta[2][i][0] = a[i];
        sta[3][i][0] = a[i];
        if(a[i] > 0) sta[2][i][0] = -INF; // 非正数范围的最大值
        if(a[i] < 0) sta[3][i][0] = INF; // 非负数范围的最小值
    }

    for(int i = 1; i <= m; i ++) {
        stb[0][i][0] = b[i];
        stb[1][i][0] = b[i];
    }

    for(int j = 1; j < 20; j ++) {
        for(int i = 1; i <= n; i ++) {
            sta[0][i][j] = min(sta[0][i][j - 1], sta[0][min(n, i + (1 << (j - 1)))][j - 1]);
            sta[1][i][j] = max(sta[1][i][j - 1], sta[1][min(n, i + (1 << (j - 1)))][j - 1]);

            sta[2][i][j] = max(sta[2][i][j - 1], sta[2][min(n, i + (1 << (j - 1)))][j - 1]);
            sta[3][i][j] = min(sta[3][i][j - 1], sta[3][min(n, i + (1 << (j - 1)))][j - 1]);
        }
    }

    for(int j = 1; j < 20; j ++) {
        for(int i = 1; i <= m; i ++) {
            stb[0][i][j] = min(stb[0][i][j - 1], stb[0][min(m, i + (1 << (j - 1)))][j - 1]);
            stb[1][i][j] = max(stb[1][i][j - 1], stb[1][min(m, i + (1 << (j - 1)))][j - 1]);
        }
    }
}

int querya(int l, int r, int id) {
    int len = lg2[r - l + 1];
    int res1 = sta[id][l][len];
    int res2 = sta[id][r - (1 << len) + 1][len];
    if(id == 0 || id == 3) return min(res1, res2);
    return max(res1, res2);
}

int queryb(int l, int r, int id) {
    int len = lg2[r - l + 1];
    int res1 = stb[id][l][len];
    int res2 = stb[id][r - (1 << len) + 1][len];
    if(id == 0) return min(res1, res2);
    return max(res1, res2);
}

ll calc(int l1, int r1, int l2, int r2) {
    ll ans = -INFll;
    // int len1 = lg2[r1 - l1 + 1], len2 = lg2[r2 - l2 + 1];

    for(int i = 0; i < 4; i ++) {
        ll res = INFll;
        ll a1 = querya(l1, r1, i);
        if(abs(a1) == INF) continue; // 不存在要continue， 主要是sta2，3的
        for(int j = 0; j < 2; j ++) {
            ll b1 = queryb(l2, r2, j);
            res = min(res, a1 * b1);
        }
        ans = max(res, ans);
    }
    return ans;
}

void debug() {
    for(int k = 0; k < 4; k ++) {
        cout << k << endl;
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j <= 2; j ++) {
                cout << sta[k][i][j] << " \n"[j == 2];
            }
        }
    }

    for(int k = 0; k < 2; k ++) {
        cout << k << endl;
        for(int i = 1; i <= m; i ++) {
            for(int j = 0; j <= 2; j ++) {
                cout << stb[k][i][j] << " \n"[j == 2];
            }
        }
    }

}

void solve()
{
    int q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int j = 1; j <= m; j ++) cin >> b[j];

    init();
    // debug();

    while(q --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << calc(l1, r1, l2, r2) << endl;
    }




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}