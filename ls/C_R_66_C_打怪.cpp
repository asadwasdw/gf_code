#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

struct r{
    int t, x, y;
}dr[N];

void solve()
{
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> dr[i].t >> dr[i].x >> dr[i].y;
    }

    sort(dr + 1, dr + n + 1, [&](r a, r b){
        return a.t < b.t;
    });

    for(int i = 1; i <= n; i ++) {
        if(m >= dr[i].x) m += dr[i].y;
    } 
    cout << m;





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