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
int dp[N];
int dp2[N];
int num[N];
int n;

void dfs1(int u,int fa){
    num[u]=1;
    for(auto v:edg[u]){
        if(v==fa)continue;
        dfs1(v,u);
        dp[u]+=dp[v]+num[v];
        num[u]+=num[v];
    }
}

void dfs2(int u,int fa){
    for(auto v:edg[u]){
        if(v==fa)continue;
        dp2[v] =  dp2[u] +n-2*num[v]; 
        dfs2(v,u);
    }
}


void solve()
{

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dfs1(1,-1);
    dp2[1]=dp[1];
    for(int i=1;i<=n;i++){
        // cout << dp[i] <<" " << num[i] <<endl;
    }
    dfs2(1,-1);
    int ans = 0;
    int mn = INF;
    for(int i=1;i<=n;i++){
        if(mn>dp2[i]){
            ans=i;
            mn=dp2[i];
        }
        // cout << dp2[i] <<endl;
    }
    cout << ans << " " << mn <<endl;
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