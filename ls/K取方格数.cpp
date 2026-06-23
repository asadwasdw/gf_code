#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

const int N = 1e4 + 10, M = 4e4 + 10;

int n, m, S, T, cnt, k;
int a[N][N];
int h[N], e[M], ne[M], f[M], w[M], idx;
int d[N], incf[N], pre[N];
bool st[N];
int F[N];

int id[51][51][4];

void add(int a, int b, int c, int d) {
    // cout << a << " " << b << " " << c << " " << d << endl;
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}


bool spfa() {
    queue<int> q;
    for(int i = S; i <= T; i ++) {
        d[i] = -INF;
        incf[i] = 0;
    }
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


void solve()
{
    clear();
    S = newnode();
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            id[i][j][0] = newnode();
            id[i][j][1] = newnode();
            id[i][j][2] = newnode();
            id[i][j][3] = newnode();

            add(id[i][j][0], id[i][j][1], 1, a[i][j]);
            add(id[i][j][0], id[i][j][2], k - 1, 0);
            add(id[i][j][2], id[i][j][3], k, 0);
            add(id[i][j][1], id[i][j][3], k, 0);
        }
    }

    T = newnode();
   
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == 1 && j == 1) {
                add(S, id[i][j][0], k, 0);
            }

            if(i == n && j == n) {
                add(id[i][j][3], T, k, 0);
            }

            if(i != 1) add(id[i - 1][j][3], id[i][j][0], k, 0);
            if(j != 1) add(id[i][j - 1][3], id[i][j][0], k, 0);
        }
    }

    EK();







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