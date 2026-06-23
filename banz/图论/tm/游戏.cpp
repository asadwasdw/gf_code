#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10, M = 2e5 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, d, m;
vector<int> p;
string s;

int h[N], e[M], ne[M], idx;
void add(int a, int b) {
    // cout << a << " " << b << endl;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}


int get(int x, char b) {
    // cout << x << " " << b << endl;
    if(s[x] == 'a' && b == 'B') return 2 * x;
    if(s[x] == 'a' && b == 'C') return 2 * x + 1;
    if(s[x] == 'b' && b == 'C') return 2 * x;
    if(s[x] == 'b' && b == 'A') return 2 * x + 1;
    if(s[x] == 'c' && b == 'A') return 2 * x ;
    return 2 * x + 1;
}

char put(int id) {
    int x = id / 2;
    int y = id % 2;
    if(s[x] == 'a' && y == 0) return 'B';
    if(s[x] == 'a' && y == 1) return 'C';
    if(s[x] == 'b' && y == 0) return 'C';
    if(s[x] == 'b' && y == 1) return 'A';
    if(s[x] == 'c' && y == 0) return 'A';
    return 'B';
}

char f(int x, char b) {
    if(s[x] == 'a' && b == 'B') return 'C';
    if(s[x] == 'a' && b == 'C') return 'B';
    if(s[x] == 'b' && b == 'C') return 'A';
    if(s[x] == 'b' && b == 'A') return 'C';
    if(s[x] == 'c' && b == 'A') return 'B';
    return 'A';
}
    
struct OP{
    int i,j;
    char a, b;
}op[N];

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
        ++scc_cnt;
        while(1) {
            int v = stk.top(); stk.pop();
            sccno[v] = scc_cnt;
            if(u == v) break;
        }
    }
}


bool check() {
    memset(h, -1, sizeof h);
    memset(dfn, 0, sizeof dfn);
    tim = idx = 0;


    for(int k = 1; k <= m; k ++) {
        auto [i, j, a, b] = op[k];
        char fa = f(i, a), fb = f(j, b);
        if(s[i] - 'a' != a - 'A') { 
            if(s[j] - 'a' != b - 'A') {
                add(get(i, a) , get(j, b));
                add(get(j, fb), get(i, fa));
            }
            else {
                add(get(i, a), get(i, fa));
            }
        }
    }

    for(int i = 2; i <= 2 * n + 1; i ++) {
        if(!dfn[i]) tarjan(i);
    }

    for(int i = 2; i <= 2 * n + 1; i += 2) {
        if(sccno[i] == sccno[i + 1]) return false;
    }

    for(int i = 2; i < 2 * n + 1; i += 2) {
        if(sccno[i] < sccno[i + 1]) cout << put(i);
        else cout << put(i + 1);
    } 
    return true;
}

void solve()
{
    cin >> n >> d >> s;
    s = " " + s;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'x') 
            p.push_back(i);
    }

    cin >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> op[i].i >> op[i].a >> op[i].j >> op[i].b;   
    }

    for(int st = 0; st < (1 << d); st ++) {
        for(int i = 0; i < d; i ++) {
           if((st >> i) & 1) s[p[i]] = 'a';
            else s[p[i]] = 'b';
        }

        if(check()) return;
    }

    cout << "-1";
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


