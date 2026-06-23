#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod = 1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
ll w[N];
int st[N];
int n,m,t;

void dfs(int u)
{
    st[u]=true;
    for(auto x:edg[u])
    {
        w[x]+=w[u];
        dfs(x);
    }
    if(edg[u].size())t-=w[u];
}


int dp[N];

int f[N];
int find(int x)
{
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}

void solve()
{
 
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)f[i]=i;

    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);st[b]=true;
        int fa = find(a);
        int fb = find(b);
        if(fa==fb){
            cout<<"0";return;
        }
        f[fa]=fb;
    }

    for(int i=1;i<=n;i++){
        if(!st[i])dfs(i);
    }

    //for(int i=1;i<=n;i++)cout<<w[i]<<endl;
    dp[0]=1;
    //cout<<t<<endl;
    

    for(int i=1;i<=n;i++)
    {
        for(int j = w[i];j<=t;j++){
            dp[j]+=dp[j-w[i]];
            dp[j]%=mod;
        }
    }
    cout<<dp[t]<<endl;
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