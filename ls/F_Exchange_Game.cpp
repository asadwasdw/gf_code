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
int a[N], cnt;
map<PII,int>SG;
int sg(int u, int v) {
    // cerr << u << " " << v << endl;
    if(u == 0) return 0;
    if(SG.count({u, v})) return SG[{u, v}];

    set<int> s;
    int res = 0;

    for(int i = 1; i <= cnt ; i ++) {
        
    }

    while(s.count(res)) res ++;
    return SG[{u,v}] = res;
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) cin >> a[cnt++];
    for(int i = 1; i <= m; i ++) cin >> a[cnt++];
    for(int i = 1; i <= k; i ++) cin >> a[cnt++];

    cout << (sg((1<<n) - 1, ((1<<m)-1) << n) ? "Takahashi":"Aoki") << endl;

    // cout << (213|123^25) << endl;
    // cout << (213|(123^25)) << endl;
    // cout << ((213|123)^25) << endl;
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