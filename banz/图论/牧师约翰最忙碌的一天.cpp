#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);  

struct T{
    int l, r, id;
}t[N][2];
int cnt = 0;

bool check(T a, T b) {
    if(a.r < b.l || a.l > b.r) return false;
    return true;
}

void add(int a, int b) {
    edg[a].push_back(b);
}


int dfn[N], low[N], tim, sccno[N], scc_cnt;
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++ tim;
    stk.push(u);
    for(auto v : edg[u]) {
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

void Tarjan(int n) {
    for(int i = 1; i <= n; i ++) {
        if(!dfn[i]) tarjan(i);
    }
} 


void solve()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i ++) {
        int s1, s2, t1, t2, d;
        scanf("%d:%d %d:%d %d", &s1, &s2, &t1, &t2, &d);
        s1 = s1 * 60 + s2;
        s2 = s1 + d - 1;
        t2 = t1 * 60 + t2 - 1;
        t1 = t2 - d + 1;
        // cout << s1 << " " << s2 << " " << t1 << " " << t2 << endl;
        t[i][0] = {s1, s2, ++ cnt};
        t[i][1] = {t1, t2, ++ cnt};
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            for(int a = 0; a < 2; a ++) {
                for(int b = 0; b < 2; b ++) {
                    if(check(t[i][a], t[j][b])) {
                        add(t[i][a].id, t[j][b ^ 1].id);
                        add(t[j][b].id, t[i][a ^ 1].id);
                    }
                }
            }
        }
    }

    Tarjan(cnt);

    for(int i = 1; i <= n; i ++) {
        if(sccno[t[i][0].id] == sccno[t[i][1].id]) {
            cout << "NO\n";
            return;
        }
    } 

    cout << "YES\n";

    auto print = [&](T a) {
        int l1 = a.l / 60, l2 = a.l % 60;
        int r1 = (a.r + 1) / 60, r2 = (a.r + 1) % 60;
        printf("%02d:%02d %02d:%02d\n",l1, l2, r1, r2);
    };

    for(int i = 1; i <= n; i ++) {
        // cout << sccno[t[i][0].id] << " " << sccno[t[i][1].id] << endl;
        if(sccno[t[i][0].id] < sccno[t[i][1].id]) {
            print(t[i][0]);
        }
        else print(t[i][1]);
    }

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}