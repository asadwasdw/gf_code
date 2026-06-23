#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N= 1000+10, M = 3 * N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m, S, T, cnt;
int a[N][N];
int h[N], e[M], ne[M], f[M], w[M], idx;
int d[N], incf[N], pre[N];
bool st[N];
int F[N];

int id[N][N][2];

void add(int a, int b, int c, int d) {
    // cout << a << " " << b << " " << c << " " << d << endl;
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}


bool spfa() {
    queue<int> q;
    // for(int i = S; i <= T; i ++) {
    //     d[i] = -INF;
    //     incf[i] = 0;
    // }

    memset(d, -0x3f, sizeof (int) * T * 4);
    memset(incf, 0,  sizeof (int) * T * 4);
    q.push(S), d[S] = 0, incf[S] = INF;

    while(q.size()) {
        int u = q.front(); q.pop();
        st[u] = false;
        
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] < d[u] + w[i]) {
                // cout << v << endl;
                d[v] = d[u] + w[i];
                pre[v] = i;
                incf[v] = min(incf[u] , f[i]);
                if(!st[v]) {st[v] = true, q.push(v);}
            }
        }
    }
    // for(int i = S; i <= T; i ++) cout << incf[i] << " \n"[i == T];
    return incf[T] > 0;
}

int flow, cost;
void EK() {
    flow = cost = 0;
    while(spfa()) {
        int t = incf[T];
        flow += t;
        cost += t * d[T];
        for(int i = T; S != i; i = e[pre[i] ^ 1]) {
            F[i] += t;
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
    cout << cost << endl;
}


void clear() {
    memset(h, -1, sizeof h);
    idx = 0;
    cnt = 0;
}

int newnode() {
    return cnt ++;
}

void solve1() {
    clear();
    S = newnode();

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m + i - 1; j ++) {
            id[i][j][0] = newnode();
            id[i][j][1] = newnode();

            // cout << i << " " << j << " ---- \n";

            add(id[i][j][0], id[i][j][1], 1, a[i][j]);

            if(i == 1) add(S, id[i][j][0], 1, 0);
            else {
                if(j != 1)        add(id[i - 1][j - 1][1], id[i][j][0], 1, 0);
                if(j != m + i - 1)add(id[i - 1][j    ][1], id[i][j][0], 1, 0);
            }
        }
    }

    T = newnode();
    for(int j = 1; j <= m + n - 1; j ++) {
        add(id[n][j][1], T, 1, 0);
    }

    EK();
}

void solve2() {
    clear();
    S = newnode();

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m + i - 1; j ++) {
            id[i][j][0] = newnode();
            id[i][j][1] = newnode();

            add(id[i][j][0], id[i][j][1], 2, a[i][j]);

            if(i == 1) add(S, id[i][j][0], 1, 0);
            else {
                if(j != 1)        add(id[i - 1][j - 1][1], id[i][j][0], 1, 0);
                if(j != m + i - 1)add(id[i - 1][j    ][1], id[i][j][0], 1, 0);
            }
        }
    }

    T = newnode();
    for(int j = 1; j <= m + n - 1; j ++) {
        add(id[n][j][1], T, 2, 0);
    }

    EK();

}


void solve3() {
    clear();
    S = newnode();

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m + i - 1; j ++) {
            id[i][j][0] = newnode();
            id[i][j][1] = newnode();

            // cout << i << " " << j << " ---- \n";

            add(id[i][j][0], id[i][j][1], INF, a[i][j]);

            if(i == 1) add(S, id[i][j][0], 1, 0);
            else {
                if(j != 1)        add(id[i - 1][j - 1][1], id[i][j][0], INF, 0);
                if(j != m + i - 1)add(id[i - 1][j    ][1], id[i][j][0], INF, 0);
            }
        }
    }

    T = newnode();
    for(int j = 1; j <= m + n - 1; j ++) {
        add(id[n][j][1], T, INF, 0);
    }

    EK();
}

void solve()
{
    cin >> m >> n;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m + i - 1; j ++) {
            cin >> a[i][j];
            // cout << a[i][j] << " \n"[j == m + i - 1];
        }
    }
    solve1();
    solve2();
    solve3();

    // cout << max({solve1(), solv2e(), solve3()});
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