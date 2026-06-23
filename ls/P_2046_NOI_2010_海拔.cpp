#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

const int N=1e6+10, M = 5e6 + 10;
vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];

void add(int a, int b, int c) {
    // cerr << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    // e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}


const int G = 510;
int id[G][G], cnt;
int dis[N];

void solve()
{
    memset(dis, 0x3f, sizeof dis);
    int n;
    cin >> n;
    S = ++ cnt, T = ++ cnt;
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= n; j ++) {
            id[i][j] = ++ cnt;
            // cout << id[i][j] << " \n"[j == n];
        }
    }


    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j < n; j ++) {
            int x; cin >> x;
            if(i == 0) {
                add(S, id[i][j], x);
            } else if(i == n) {
                add(id[i - 1][j], T, x);
            } else {
                add(id[i - 1][j],id[i][j], x);
            }
        }
    }  // >



    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= n; j ++) {
            int x; cin >> x;
            if(j == 0) {
                add(id[i][j], T, x);
            } else if(j == n) {
                add(S, id[i][j - 1], x);
            } else {
                // cout << id[i][j] << " " << id[i][j - 1] << " " << x <<  endl;
                add(id[i][j], id[i][j - 1], x);
            }
        }
    } 


    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j < n; j ++) {
            int x; cin >> x;
            if(i == 0) {
                add(id[i][j], S, x);
            } else if(i == n) {
                add(T, id[i - 1][j], x);
            } else {
                add(id[i][j],id[i - 1][j], x);
            }
        }
    }  

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= n; j ++) {
            int x; cin >> x;
            if(j == 0) {
                add(T, id[i][j],x);
            } else if(j == n) {
                add(id[i][j - 1], S, x);
            } else {
                // cout << id[i][j] << " " << id[i][j - 1] << " " << x <<  endl;
                add(id[i][j - 1], id[i][j], x);
            }
        }
    } 

    priority_queue<PII,vector<PII>, greater<PII>> q;
    q.push({0, S});
    dis[S] = 0;
    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
        if(dis[u] < d) continue;

        for(int i = h[u]; ~i; i = ne[i]) {
            int w = f[i], v = e[i];
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    cout << dis[T] << endl;

}


signed main()
{
    memset(h, -1, sizeof h);
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