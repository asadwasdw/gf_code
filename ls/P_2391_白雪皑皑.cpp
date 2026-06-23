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
int f[N];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int a[N];

void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = m; i >= 1; i --) {
        int l = (i * p + q) % n + 1;
        int r = (i * q + p) % n + 1;
        if(l > r) swap(l, r);

        for(int j = find(l); j <= r; j = find(j)) {
            a[j] = i;
            f[j] = find(j + 1);
        }
    }

    for(int i = 1; i <= n; i ++) cout << a[i] << endl;


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