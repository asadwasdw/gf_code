// #pragma GCC optimize(2)
#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10, M = 4e6 + 10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


int h[N], ne[M],idx,e[M];
int id[N][2], now;
int f[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    f[a] = b;
}

void add(int a, int b) {
    // cout << a << " " << b << endl;
    // edg[a].push_back(b);
    merge(a, b);
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfn[N], low[N], tim, sccno[N], scc_cnt;
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++ tim;
    stk.push(u);
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!sccno[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(dfn[u] == low[u]) {
        ++ scc_cnt;
        while(1) {
            int v = stk.top(); stk.pop();
            sccno[v] = scc_cnt;
            if(u == v) break;
        }
    }
}

int ans = 0;
void Tarjan(int n) {
    for(int i = 1; i <= n; i ++) {
        if(!dfn[i]) tarjan(i);
    }
} 

/*

条件判断
1 a V b(至少有1个为true) <=> fa -> b, fb -> a
2 a b 不同时为true       <=> fa -> b, fb -> a
3 a 为 1   <=> a V a <=> fa -> a
*/

void solve()
{
    ans = 0;
    int n, m;
    scanf("%d%d",&n,&m);
    now = tim = idx = scc_cnt = 0;
    for(int i = 1; i <= n; i ++) {
        id[i][0] = ++ now;
        id[i][1] = ++ now;
    }
    
    // memset(h, -1, sizeof h);
    for(int i = 0; i <= now + 9; i ++) {
        h[i] = -1;
        sccno[i] = dfn[i] = low[i] = 0;
        f[i] = i;
    }

    vector<string> s(n + 1);
    vector<vector<int>>edg(m + 1);
    bool ky = true;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] =  " " + s[i];

        for(int j = 1; j <= m; j ++) {
            if(s[i][j] == '1') {
                edg[j].push_back(i);
                if(edg[j].size() + edg[m - j + 1].size() >= 3) {
                    ky = false;
                }
            }
        }
    }
    if(!ky) {
        cout << "0\n";
        return;
    }

    int l = 1, r = m;
    while(l <= r) {

        if(l == r) {
            if(edg[l].size() >= 2) {
                cout << "0\n";
                return;
            }
            break;
        }

        for(auto u : edg[l]) {
            for(auto v:edg[r]) {
                add(id[u][0], id[v][0]);
                add(id[v][0], id[u][0]);
                add(id[v][1], id[u][1]);
                add(id[u][1], id[v][1]);
            }
        }

        for(auto u:edg[l]) {
            for(auto v:edg[l]){
                if(u == v) continue;
                add(id[u][0], id[v][1]);
                add(id[v][1], id[u][0]);
            }
        }

        for(auto u:edg[r]) {
            for(auto v:edg[r]){
                if(u == v) continue;
                add(id[u][0], id[v][1]);
                add(id[v][1], id[u][0]);
            }
        }
        l ++, r --;
    }

    Tarjan(now);
    for(int i = 1; i <= n; i ++) {
        if(sccno[id[i][0]] == sccno[id[i][1]]) {
            cout << "0\n";
            return;
        }
    }

    auto qmi = [&](ll a, ll b) -> ll {
        ll res = 1;
        while(b) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    for(int i = 1; i <= now; i ++) {
        if(find(i) == i) ans++;
    }

    cout << qmi(2,ans/2)%mod << endl;
}


signed main()
{
    int t;t=1;
    memset(h, -1, sizeof h);
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}