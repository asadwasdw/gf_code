#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

// vector<vector<int>>adj[2] (N);
vector<vector<vector<int>>> adj(2, vector<vector<int>>(N));

int ans[5];
void check(int u) {
    map<int,bool> st;
    for(auto v : adj[0][u])st[v] = true;

    for(auto v: adj[1][u]) {
        if(st[v] == false) continue;
        ans[2] ++;

        for(int i = 0; i < 2; i ++) {
            for(auto v2 : adj[i][v]) {
                if(v2 == u) continue;

                for(auto v3 : adj[i^1][v2]) {
                    if(v3 == u) {
                        // cout << u << " " << v << " " << v2 << endl;
                        ans[3] ++;
                    }
                }
            }
        }
    } 
}

int f[N], num[N];

int find(int x) {
    if(f[x] != x) return f[x] = find(f[x]);
    return f[x];
} 

void merge(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    num[b] += num[a];
    f[a] = b;
}

void check2(int u) {
    // cout << u << endl;
    set<int> s[2];

    for(int i = 0; i < 2; i ++) {
        queue<int> q;
        q.push(u);

        while(q.size()) {
            int u = q.front(); q.pop();
            s[i].insert(u);
            for(auto v : adj[i][u]) {
                if(s[i].count(v)) continue;
                q.push(v);
            }
        }
    }
    // cout << u << endl;
    // cout << s[0].size() << " " << s[1].size() << endl;
    if(s[0].size() == 4 && s[1].size() == 4) ans[4] ++; 

}

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}


void solve()
{
    int n, m; cin >> n >> m;
    ans[1] = n;
    for(int i = 1; i <= n; i ++) {
        f[i] = i;
        num[i] = 1;
    }
    for(int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[c][a].push_back(b);
        adj[c][b].push_back(a);
        merge(a, b);
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < 2; j ++) {
            sort(adj[j][i].begin(), adj[j][i].end());
            adj[j][i].erase(unique(adj[j][i].begin(), adj[j][i].end()), adj[j][i].end());
        }
    }

    for(int i = 1; i <= n; i ++) {
        check(i);
        if(i == find(i) && num[i] == 4) check2(i);
    }

    cout << (ans[1] + ans[2]*qmi(2, mod - 2) + ans[3]*qmi(2, mod - 2) + ans[4]) % mod << endl;
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