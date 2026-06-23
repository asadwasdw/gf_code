#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int f[N], d[N], cnt[N];
int find(int x) {
    if(f[x] != x) {
        int root = find(f[x]);
        d[x] += d[f[x]];
        f[x] = root;
    }
    return f[x]; 
}

void merge(int x, int y, int len) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    d[fx] = len + d[y] - d[x];
    cnt[fy] += cnt[fx];
    f[fx] = fy;
}

void solve()
{
    int n = 3e4;
    for(int i = 1; i <= n; i ++) {
        f[i] = i;
        cnt[i] = 1;
    }

    int q;
    cin >> q;
    while(q --) {
        char op;
        int x, y;
        cin >> op;
        if(op == 'M') {
            cin >> x >> y;
            find(x);
            find(y);
            merge(x, y, d[x] + cnt[find(y)] - d[y]);
        } else {
            cin >> x;
            find(x);
            cout << d[x] << endl;
        }
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
    return 0;
}