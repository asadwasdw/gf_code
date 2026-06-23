#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=30, M = 1<<15;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int h[N], e[M], ne[M], w[M], idx;
int n, m, k;
int dp[50][1<<15];
int ans[N];
array<int,3> edg[M];
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void solve1() {
    for(int i = 0; i < n; i ++) {
        for(int j = 1; j < (1 << k);  j ++) {
            dp[i][j] = INF;
        }
    }

    for(int i = 0; i < k; i ++) {
        int x = i;
        dp[x][1<<i] = 0;
    }

    auto dj = [&](int st) {
        priority_queue<PII, vector<PII>, greater<PII>>q;
        vector t(n, 0);
        for(int i = 0; i < n; i ++) {
            q.push({dp[i][st], i});
        }

        while(q.size()) {
            auto [dis, u] = q.top(); q.pop();
            if(t[u]) continue;
            t[u] = 1;

            for(int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                if(dp[v][st] > dis + w[i]) {
                    dp[v][st] = dis + w[i];
                    q.push({dp[v][st], v});
                }
            }
        }
    };

    for(int st = 1; st < (1 << k); st ++) {
        for(int t = st; t; t = (t - 1) & st) {
            for(int i = 0; i < n; i ++) {
                dp[i][st] = min(dp[i][st], dp[i][t] + dp[i][st ^ t]);
            }
        }
        dj(st);
    }

    for (int i = 0; i < k; ++ i) {
        ans[i] = dp[i][(1 << i + 1) - 1];
    }
}

int f[N];
inline int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

inline void merge(int a, int b) {
    a = find(a), b = find(b);
    f[a] = b;
}


inline void solve2() {
    vector<array<int,3>> e;
    map<int,int> st;
    for(int st = 0; st < (1 << (n - k)); st ++) {
        for(int i = 0; i <= n; i ++) f[i] = i;
        int res = 0;
        for(int i = 0; i < m; i ++) {
            auto [u, v, w] = edg[i];
            if(u >= k && (((st >> (u - k)) & 1) == 0)) continue;
            if(v >= k && (((st >> (v - k)) & 1) == 0)) continue;
            e.push_back(edg[i]);
            u = find(u), v = find(v);
            if(u == v) continue;
            merge(u, v);
            res += w;
        }

        
     

        for(int i = 0; i < n; i ++) {
            if(i >= k && (((st >> (i - k)) & 1) == 0)) continue;
            if(find(i) != find(0)) res = INF;
        }

        for(int i = 0; i < (n - k); i ++) {
            if(((st >> i)&1) == 0) break;
            ans[i + k] = min(ans[i + k], res);
        }
    }
}



void solve()
{
    while(cin >> n >> m) {
        memset(h, -1, sizeof h);
        memset(ans, 0x3f, sizeof ans);
        idx = 0;
    
        for(int i = 0; i < m; i ++) {
            int u,v,w;
            cin >> u >> v >> w;
            u--, v--;
            add(u, v, w);
            add(v, u, w);
            edg[i] = {u, v, w};
        }

        sort(edg, edg + m, [&](array<int,3> a, array<int,3> b){
            return a[2] < b[2];
        });

        k = max(n/2,1);
        solve1();
        solve2();
        for(int i = 1; i < n; i ++) cout << ans[i] << endl;
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
}