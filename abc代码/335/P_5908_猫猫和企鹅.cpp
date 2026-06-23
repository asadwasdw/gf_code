#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int ans=-1;
int n,k;

void dfs(int u,int fa,int dis){
    // cout << u << endl;
    ans++;
    if(dis==k)return;
    for(auto v:edg[u]) {
        if(v==fa)continue;
        
        dfs(v,u,dis+1);
    }
}

void solve()
{
    cin>>n>>k;
    // cout << n << " "  << k << endl;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        // cout << a << ' '<< b <<endl;
    }

    dfs(1,-1,0);

    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}