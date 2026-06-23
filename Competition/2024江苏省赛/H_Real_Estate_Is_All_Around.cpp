#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
const int N = 1e3 + 10, M = 5e3 + 10;
int n,m;
int h[N], e[M], ne[M] ,f[M], w[M],idx;

void add(int a, int b, int c, int d) { // a -> b 容量是c, 单位价格是 d
    e[idx] = b, f[idx] = c, w[idx] = d,  ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx ++;
}


int S, T;
int d[N];
int incf[N];
int pre[N];
int st[N];


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
    flow = cost = 0;
    while(spfa()) {
        int t = incf[T]; // 此时流量
        flow += t, cost += t * d[T];
        for(int i = T; i != S; i = e[pre[i] ^ 1]) {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
}

void solve()
{
    cin >> n;
    int now = 2;
    S = 0, T = 4 * n + 1;
    int sum = 0;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++) {
        int op, x;
        cin >> op;
        int id =  4 * (i - 1) + 1;
        int id1 = 4 * (i - 1) + 2;
        int id2 = 4 * (i - 1) + 3;
        int id3 = 4 * (i - 1) + 4;

        if(i != 1) {
            add(id1  - 4, id1, INF,0);
            add(id2  - 4, id2, INF,0);
            add(id3  - 4, id3, INF,0);
        }

        if(op == 2) {
            add(id1, T, 1, 0);
            add(id2, T, 1, 0);
            add(id3, T, 1, 0);
            continue;
        }

        cin >> x;
        sum += x;

        add(S, id, 1, 0);
        add(id, id1, 1, 1);
        add(id, id2, 1, (x + 9) / 10);
        add(id, id3, 1, 0);
        add(id, T, 1, x);
    }

    int flow, cost = 0;
    EK(flow, cost);
    cout << sum  -  cost << endl;

    idx = 0;


    // for(int i = 0; i <= idx; i += 2) {
    //     if(f[i] == 0) {
    //         cout << e[i ^ 1] << " " << e[i] << endl;
    //     }
    // }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}