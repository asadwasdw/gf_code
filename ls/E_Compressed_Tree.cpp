#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n;
int a[N];
int ans=0;
int dp[N];


void dfs(int u,int fa) {
    dp[u] = a[u];
    ans = max(ans,a[u]);
    vector<int>x,y;
    for(auto v: edg[u]) {
        if(v == fa) continue;
        dfs(v,u);
        dp[u] = max(dp[u],dp[v]);
        ans = max(dp[v]+a[u],ans);
        if(dp[v]>=0)x.push_back(dp[v]);
        else y.push_back(dp[v]);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    if(x.size() > 1) {
        int sum = a[u];
        for(auto t:x)sum+=t;
        dp[u] = max(sum,dp[u]);
        ans = max(ans,x[x.size()-1]+x[x.size()-2]);
        if(x.size()>2) {
            ans=max(ans,sum);
        }
        else if(y.size()) ans = max(sum+y.back(),ans);
    }

    if(x.size()==1 && y.size()) {
        dp[u] = max(dp[u],a[u]+x.back()+y.back());
        ans = max(ans,x.back()+y.back());
    }
    // cout<<u<<" "<<ans<<" "<<dp[u]<<endl;
}

void solve()
{
    int n; cin >> n; 
    for(int i=1; i<=n; i++ ) {
        cin>>a[i];
        edg[i].clear();
    }

    for(int i=1; i<n; i++) {
        int x, y; cin>>x>>y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    
    dfs(1,-1);
    cout<<ans<<"\n";

    ans = 0;
    // for(int i=1;i<=n;i++)edg[i].clear();
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}