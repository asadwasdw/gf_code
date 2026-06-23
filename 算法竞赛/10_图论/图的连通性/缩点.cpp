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
vector<vector<int>>redg(N);
int w[N];
int W[N];
int sccno[N];
int st[N];
int cnt = 0;
vector<int>s;

map<PII,int>ST;

void dfs1(int u)
{
    if(st[u])return;
    st[u]=1;
    for(auto t:edg[u]){
        dfs1(t);
    }
    s.push_back(u);
}

void dfs2(int u)
{
    if(sccno[u])return;
    sccno[u]=cnt;
    W[cnt]+=w[u];
    for(auto t:redg[u]){
        dfs2(t);
    }
}

int dp[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        redg[b].push_back(a);
    }

    for(int i=1;i<=n;i++)dfs1(i);

    for(int i=n-1;i>=0;i--){
        if(!sccno[s[i]]){
            ++cnt;
            dfs2(s[i]);
        }
    }

   // for(auto t:s)cout<<t<<" ";cout<<endl;

    //cout<<cnt<<endl;

   // for(int i=1;i<=cnt;i++)cout<<W[i]<<" ";cout<<endl;

    for(int i=1;i<=cnt;i++)dp[i]=W[i];

    ll ans = dp[1];

    for(int i=n-1;i>=0;i--){
        for(auto t:edg[s[i]]){
            if(sccno[t]==sccno[s[i]])continue;
            if(ST[{sccno[s[i]],sccno[t]}])continue;
            ST[{sccno[s[i]],sccno[t]}]+=1;
           //cout<<sccno[s[i]]<<" "<<sccno[t]<<endl;
            
            dp[sccno[t]]=max(dp[sccno[t]],dp[sccno[s[i]]]+W[sccno[t]]);
            ans = max({ans,dp[sccno[t]],dp[sccno[s[i]]]});
        }
    }

   // for(int i=1;i<=cnt;i++)cout<<dp[i]<<endl;

    cout<<ans<<endl;





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