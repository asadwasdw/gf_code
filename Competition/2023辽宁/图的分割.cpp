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
struct e{
    int u, v, w;
}edg[N];
int f[N];
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
int cnt = 0;
void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    cnt--;
    f[x] = y;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) {
        cin >> edg[i].u >> edg[i].v >> edg[i].w;
    }
    sort(edg+1, edg+m +1, [&](e a, e b){
        return a.w < b.w;
    });
    cnt = n;
    if(cnt == 2) {
        cout << edg[m].w;
        return;
    }
    else if(n == 1){
        cout << "0";
        return;
    }
    
    for(int i = m; i >= 1; i --) {
        if(cnt == 2) {
            cout << edg[i].w;
            return;
        }
        merge(edg[i].u, edg[i].v);
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