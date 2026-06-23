#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
const int N = 55 * 10, M = 4 * N * N ;

int n, m, S, T;
int h[N], e[M], f[M], w[M], ne[M],idx;

void add(int a, int b, int c, int d) { // a -> b 容量是c, 单位价格是 d
    e[idx] = b, f[idx] = c, w[idx] = d,  ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx ++;
}

bool st[N];
int d[N],pre[N],incf[N];



bool spfa() {
    memset(d, 0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    queue<int>q;

    q.push(S), d[S] = 0, incf[S] = INF;

    while(q.size()) {
        int u = q.front();q.pop();
        st[u] = false;

        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] > d[u] + w[i]) {
                d[v] = d[u] + w[i];
                pre[v] = i;
                incf[v] = min(f[i], incf[u]); // spfa 每次只找一条边
                if(!st[v]) {
                    st[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return incf[T] > 0; 
}


void EK(int& flow, int& cost) {
    flow = 0, cost = 0;
    while(spfa()) {
        int t = incf[T];
        flow += t, cost += t * d[T];
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        } 
    }
}

int a[120][120];


int js(int mid) {
    idx = 0;
    memset(h, -1, sizeof h);
    S = 0, T = 4 * n + 1;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int ida = n + j * 2 - 1, idb = n + j * 2;
            if(j <= mid) add(i, ida, 1, a[i][j * 2 - 1]);
            else add(i, idb, 1, a[i][j * 2]);
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            add(n + 2 * j - 1, i + 3 * n,  1, a[n + i][j * 2 - 1]);
            add(n + 2 * j    , i + 3 * n,  1, a[n + i][j * 2    ]);
        }
    }

    for(int i = 1; i <= n; i ++) {
        add(S, i, 1, 0);
        add(3 * n + i, T, 1, 0);
    }

    int flow, cost = 0;
    EK(flow, cost);
    return cost;
}

int ans1[N],ans2[N];


void solve()
{
    cin >> n;

    S = 0;

    for(int i = 1; i <= 2 * n; i ++) {
        for(int j = 1; j <= 2 * n ; j ++) {
            cin >> a[i][j];
        }
    }

    int ans = INF, j = 0;

    for(int i = 1; i <= n; i ++) {
        int t = js(i);
        if(ans > t) {
            ans = t;
            j = i;
        }
    }

    js(j);
    int mid = j;
    cout << ans << endl;

    for(int i = 0; i <= idx; i += 2) {
        int u = e[i ^ 1], v = e[i];
     
        
        if(u && u <= n && v > n && v <= 3 * n && f[i] == 0) {
            // if(f[i] == 0)  cout << u << " " << v << endl;
            ans1[u] = (v - n + 1) / 2;
        } 

        if(v > 3 * n && v <= 4 * n && f[i] == 0) {
            ans2[(u - n + 1)/2] = v - 3 * n;
        }
    }

    // for(int i = 1; i <= n; i ++) cout << ans1[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++) cout << ans2[i] << " \n"[i == n];

    for(int i = 1; i <= n; i ++) {
        int j = i;
        cout << j << " ";
        j = ans1[j];
        cout << j ;
        if(j <= mid) cout << "A ";
        else cout << "B ";
        j = ans2[j];
        cout << j << endl; 
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